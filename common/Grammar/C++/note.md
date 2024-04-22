# 实用语法知识补充
## 多线程-锁
1. 案例：
    ```c++
    #include <boost/thread/mutex.hpp>
    #include <boost/thread/shared_mutex.hpp>
    cv::Mat cam_image_copy;
    boost::shared_mutex mutex_image_callback;
    bool image_status = false;
    boost::shared_mutex mutex_image_status;
    ...
    // 对变量进行写操作。
    /* 
     * 之所以在花括号中，是因为在C++中，使用花括号 {} 可以定义一个作用域，这在编写多线程代码时非常有用。
     * 如下代码中，boost::unique_lock<boost::shared_mutex> 类型的 lockImageCallback 对象在花括号内部被创建。
     * 这样做的好处是，当程序执行到作用域结束时，lockImageCallback 对象会被销毁，这会触发它的析构函数，从而释放锁。
     * 这确保了在作用域结束时自动释放锁，避免了可能的死锁或资源泄漏问题。
     */
    {
        boost::unique_lock<boost::shared_mutex> lockImageCallback(mutex_image_callback);
        cam_image_copy = cam_image->image.clone();
    }
    {
        boost::unique_lock<boost::shared_mutex> lockImageStatus(mutex_image_status);
        image_status = true;
    }
    ...
    // 对变量进行读操作，在函数中也是在花括号中
    bool getImageStatus(void)
    {
        // 因为都是对image_status这个变量进行访问，所以尽量用同一个锁mutex_image_status
        boost::shared_lock<boost::shared_mutex> lock(mutex_image_status);
        return image_status;
    }
    ```
