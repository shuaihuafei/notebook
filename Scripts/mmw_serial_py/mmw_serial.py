import serial
import threading
import signal
import time

data_queue = []
running = True  # 线程运行标志
serial_wrapper = None  # 全局串口对象

class SerialWrapper:
    def __init__(self, port, baudrate, bytesize, parity, stopbits, timeout):
        self.port = port
        self.baudrate = baudrate
        self.bytesize = bytesize
        self.parity = parity
        self.stopbits = stopbits
        self.timeout = timeout
        self.serial = None

    def __enter__(self):
        self.open_serial()
        return self

    def __exit__(self, exc_type, exc_val, exc_tb):
        self.close()

    def open_serial(self):
        try:
            self.serial = serial.Serial(
                port=self.port,
                baudrate=self.baudrate,
                bytesize=self.bytesize,
                parity=self.parity,
                stopbits=self.stopbits,
                timeout=self.timeout
            )
            print(f"Serial port configured: BaudRate = {self.baudrate}, StopBits = {self.stopbits}, Parity = {self.parity}")
            return True
        except serial.SerialException as e:
            print(f"Error opening serial port: {e}")
            return False

    def close(self):
        if self.serial and self.serial.is_open:
            self.serial.close()
            print("Serial port closed")

    def write_data(self, data):
        global running  # 引用全局运行标志
        while running:
            try:
                self.serial.write(data)
                print(f"Data written to {self.port}: {' '.join(f'{b:02x}' for b in data)}")
                time.sleep(0.2)  # 等待一段时间，模拟间隔发送
            except serial.SerialException as e:
                print(f"Error writing to {self.port}: {e}")

    def read_data(self):
        global running  # 引用全局运行标志
        while running:
            try:
                if self.serial.in_waiting > 0:
                    read_data = self.serial.read(self.serial.in_waiting)
                    if read_data:
                        self.process_received_data(read_data)
            except serial.SerialException as e:
                print(f"Error reading from {self.port}: {e}")

    def process_received_data(self, data):
        global data_queue
        data_queue.extend(data)
        print(f"Current data_queue: {' '.join(f'{b:02x}' for b in data_queue)}")
        
        while len(data_queue) >= 7:
            if data_queue[0] == 0x01 and data_queue[1] == 0x03 and data_queue[2] == 0x02:
                valid_data = data_queue[:7]
                print(f"Valid data found: {' '.join(f'{b:02x}' for b in valid_data)}")

                combined_value = (valid_data[3] << 8) | valid_data[4]
                print(f"Measure Distance is: {combined_value} cm")

                data_queue = data_queue[7:]
            else:
                data_queue.pop(0)

def signal_handler(sig, frame):
    global running, serial_wrapper
    print("Ctrl+C detected, cleaning up...")
    running = False

def main():
    write_buffer = bytes([0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A])

    global serial_wrapper

    with SerialWrapper("/dev/ttyUSB0", 115200, serial.EIGHTBITS, serial.PARITY_NONE, serial.STOPBITS_ONE, 1) as serial_wrapper:
        signal.signal(signal.SIGINT, signal_handler)

        send_thread = threading.Thread(target=serial_wrapper.write_data, args=(write_buffer,))
        receive_check_thread = threading.Thread(target=serial_wrapper.read_data)

        send_thread.start()
        receive_check_thread.start()

        send_thread.join()  # 等待发送线程结束

    print("\nSerial communication ended")

if __name__ == "__main__":
    main()
