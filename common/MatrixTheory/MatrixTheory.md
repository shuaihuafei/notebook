# 视频：[B站](https://www.bilibili.com/video/BV1Mt411k7Rq/?spm_id_from=333.1245.0.0&vd_source=a5f4029436fab3ad44f642e3a69eb1d1)
# 01 复习与引申(1) P001-005
## 矩阵理论
求矩阵A的k次幂，如果A有相似对角阵，则直接利用相似对角阵求解(如上图)。
![picture 0](.assets_IMG/MatrixTheory/IMG_20230921-210506437.png)  
如果没有相似对角阵，则需要找一个简单的但又与A相似的矩阵求解(如下图)。
![picture 1](.assets_IMG/MatrixTheory/IMG_20230921-211141883.png)  

在求矩阵极限时，老师的笔记是这样子的，看不太懂，以后再来看。  
时间：大约P01-25:00  
![picture 2](.assets_IMG/MatrixTheory/IMG_20230921-212329696.png)  
矩阵极限的求解对于求解矩阵函数好像是有帮助的，所以这段可以以后再看。  
时间：大约P01-30:30
![picture 3](.assets_IMG/MatrixTheory/IMG_20230921-212558861.png)  
![picture 4](.assets_IMG/MatrixTheory/IMG_20230921-212830104.png)  
![picture 5](.assets_IMG/MatrixTheory/IMG_20230921-213119406.png)  

如果方程组有解且并不是唯一解，如下图，请问如何恰当地表达图中的矩阵G。
![picture 6](.assets_IMG/MatrixTheory/IMG_20230921-213743222.png)  

# 02 复习与引申(2) P006-024
## 矩阵乘法中应注意的问题
矩阵的乘法中存在这种现象，就是矩阵本身并不等于0，但是想乘后等于0，此时称这连个矩阵为非零零因子。  
![picture 8](.assets_IMG/MatrixTheory/IMG_20230922-163001166.png)  
![picture 7](.assets_IMG/MatrixTheory/IMG_20230922-162939676.png)  

此板书为PDF第8页例题求解过程。其中数量矩阵，指的是设I是单位矩阵, k是任何数,则k*I称为数量矩阵。  
![picture 9](.assets_IMG/MatrixTheory/IMG_20230922-163728822.png)  

平凡差公式不适用于矩阵。  
![picture 10](.assets_IMG/MatrixTheory/IMG_20230922-165010860.png)  

## 分块矩阵的乘法规则


## 一些特殊的分块形式
下图是，A按列分块，B不分块的计算结果。然后这样计算能得到两个结论。  
![picture 0](.assets_IMG/MatrixTheory/IMG_20230925-220659774.png)  
![picture 3](.assets_IMG/MatrixTheory/IMG_20230925-222544509.png)  

若$AB=O$，则$r(A)+r(B)\leq n$，也就是说两矩阵的秩之和，不会超过A的列数，也不会超过B的行数，没懂，以后再看。  
时间：大约P02-43:58  
![picture 2](.assets_IMG/MatrixTheory/IMG_20230925-222518880.png)  
![picture 4](.assets_IMG/MatrixTheory/IMG_20230925-222551878.png)  

下图中是用的分块矩阵来进行证明的，并且使用了数学归纳法。  
![picture 11](.assets_IMG/MatrixTheory/IMG_20230926-184903135.png)  

## 非齐次线性方程组

## 齐次线性方程组的基础解系
下图中红字是基础解系的要求。  
![picture 5](.assets_IMG/MatrixTheory/IMG_20230926-193738941.png)  
![picture 6](.assets_IMG/MatrixTheory/IMG_20230926-193842348.png)  

下图红字为简化阶梯矩阵的要求。
![picture 7](.assets_IMG/MatrixTheory/IMG_20230926-195510170.png)  

其中$A^H$表示为A的共轭转置。  
![picture 8](.assets_IMG/MatrixTheory/IMG_20230926-202213343.png)  

两个证明题，比较难，是借助齐次线性方程组的基础解系来求解的。这里讲解的很清晰，跟之前李永乐讲解的转置的那个差不多。看图片如果回忆不起来，可以再听一遍。  
时间：大约P02-01:10:40  
![picture 9](.assets_IMG/MatrixTheory/IMG_20230926-203433348.png)  
![picture 10](.assets_IMG/MatrixTheory/IMG_20230926-203923335.png)  
![picture 11](.assets_IMG/MatrixTheory/IMG_20230926-204352435.png)  

# 03 复习与引申(3) P025-032
## 向量组的极大无关组及秩
下图为举例，求解极大线性无关组的过程。
![picture 12](.assets_IMG/MatrixTheory/IMG_20230926-211143270.png)  
![picture 13](.assets_IMG/MatrixTheory/IMG_20230926-213001193.png)  
## 矩阵的秩
下图中为证明题过程。不过最下面笔记写错了，应该是$r(A)=r(AB)$。
![picture 14](.assets_IMG/MatrixTheory/IMG_20230927-152227390.png)  

下图中证明小于等于用的是下下张图中的第1个性质，证明大于等于勇的是下下图中的第3个性质。  
![picture 15](.assets_IMG/MatrixTheory/IMG_20230927-154210796.png)  
![picture 16](.assets_IMG/MatrixTheory/IMG_20230927-154323854.png)  

## 矩阵的等价标准形
下图为证明$r(B)=r=r(C)$的过程。  
![picture 17](.assets_IMG/MatrixTheory/IMG_20230927-173547725.png)  

证明满秩分解。但是难点在于找到P和Q。  
![picture 18](.assets_IMG/MatrixTheory/IMG_20230927-174050723.png)  

矩阵B取矩阵A的极大无关组，C为A的每一个列向量，用A的极大线性无关组的组合系数。所以最终导向就是要求矩阵A的极大线性无关组。  
![picture 12](.assets_IMG/MatrixTheory/IMG_20231003-193144089.png)  

满秩分解举例。
![picture 13](.assets_IMG/MatrixTheory/IMG_20231003-195712510.png)  

# 04 线性空间与线性变换(1) P033-042
## 1 线性空间和线性变换
## 1.1 线性空间的定义
## 1.1.1 线性空间的定义
这是苏州大学出版社教材上关于线性空间的定义，注意不光有八条运算法则，还要有两种运算也要满足(运算的结果也要属于原先的空间)：  
![picture 55](.assets_IMG/MatrixTheory/IMG_20231006-111339332.png)  

下图中，其中1-4是针对加法而言，5-6是针对数乘而言，7-8是针对数乘和加法运算而言的。  
![picture 14](.assets_IMG/MatrixTheory/IMG_20231003-201803094.png)  

![picture 15](.assets_IMG/MatrixTheory/IMG_20231003-204612735.png)  
![picture 16](.assets_IMG/MatrixTheory/IMG_20231003-204705520.png)  
其中$F_n[x]$表示关于x的多项式，其中x的系数在$F$中，x的最大次数小于n。
![picture 17](.assets_IMG/MatrixTheory/IMG_20231003-204811138.png)  
![picture 18](.assets_IMG/MatrixTheory/IMG_20231003-210301689.png)  
其中对于第7、8条，V不是F上的线性空间。  
这两个是不满足数乘运算，即$\forall k\in F,\alpha \in V$时，$k\alpha \notin V$。  
![picture 19](.assets_IMG/MatrixTheory/IMG_20231003-210832326.png)  
![picture 20](.assets_IMG/MatrixTheory/IMG_20231003-211044899.png)  
注意，这里新定义的运算，是针对线性空间V的，对于数域F上的元素，加法还是普通的加法。比如说下下张图中的$(k+l)$就是简单的相加运算。
![picture 21](.assets_IMG/MatrixTheory/IMG_20231003-211707418.png)  
![picture 22](.assets_IMG/MatrixTheory/IMG_20231003-212140984.png)  

## 1.1.2 线性空间的性质
这里是证明零向量唯一，他是假设了如果存在两个零元素，然后这两个零元素一定相等。  
![picture 23](.assets_IMG/MatrixTheory/IMG_20231005-144604377.png)  
证明负元素唯一。  
![picture 24](.assets_IMG/MatrixTheory/IMG_20231005-151934580.png)  
![picture 25](.assets_IMG/MatrixTheory/IMG_20231005-152345328.png)  
这里应该是写错了，应该是$x=\beta-\alpha$。  
![picture 26](.assets_IMG/MatrixTheory/IMG_20231005-152431818.png)  
这里用的应该是结合律。  
![picture 27](.assets_IMG/MatrixTheory/IMG_20231005-152537847.png)  
这里的 $\theta$ 表示0向量。  
![picture 28](.assets_IMG/MatrixTheory/IMG_20231005-152613813.png)  

## 1.2 基、维数和坐标
## 1.2.1 基、维数和坐标
这里是一个例子，证明4个矩阵线性无关。并且这里确实是无关的。  
![picture 29](.assets_IMG/MatrixTheory/IMG_20231005-161720037.png)  
这个例子是求证$\alpha1$、$\alpha2$、$\alpha3$的关系，这里使用的证明方式在线性代数中很常见，就是通过假设常数的方式，然后分别求解k1、k2、k3是否有非零解。  
![picture 30](.assets_IMG/MatrixTheory/IMG_20231005-162627497.png)  
在这个例子中$\alpha1$、$\alpha2$线性无关。  
![picture 31](.assets_IMG/MatrixTheory/IMG_20231005-163210312.png)  
这里对于第4个例子，他与第3个例子不同的地方就在于数域不同，但是第4个例子中的$\alpha1$、$\alpha2$是线性相关的，因为当$a=1，b=i$时，是符合条件的。  
![picture 32](.assets_IMG/MatrixTheory/IMG_20231005-163555121.png)  
这里是老师补充了一个例子，要求是：证明当$V=R^+,F=R$时，$\alpha=2,\beta=3$，二者线性相关。  
![picture 33](.assets_IMG/MatrixTheory/IMG_20231005-165011647.png)  

# 05 线性空间与线性变换(2) P043-053
## 1.2.2 定义(基，维数)
由定义可见，维数就是基的个数。  
![picture 97](.assets_IMG/MatrixTheory/IMG_20231020-170926335.png)  

下图中，对于$V={\theta}$这个空间，只有一个0元素，所以基不存在，因为该线性空间中不存在线性无关的向量。  
对于$V=F[x]$这个空间，x的次方可以取无限大，所以其中维数也是无限的，则其基不存在。  
但是在这门课中，不考虑无限维的情况。  
![picture 36](.assets_IMG/MatrixTheory/IMG_20231005-173443760.png)  

下面是6个例子，分别找出他们的基：  
这个例子中讲解的是，对于$V=F^n$，最简单的基。也称为自然基。
![picture 37](.assets_IMG/MatrixTheory/IMG_20231005-190513361.png)  
这里例子中展示的是，对于$V=F^{2\times2}$，最简单的基。
![picture 38](.assets_IMG/MatrixTheory/IMG_20231005-194739962.png)  
这里例子中展示的是，对于$V=F_n[x]$，最简单的基。
![picture 39](.assets_IMG/MatrixTheory/IMG_20231005-195347492.png)  
对于复数空间，可以用1和i来作为基。为什么是这样，可以联想x轴为实数轴，y轴为虚数轴的坐标系。
![picture 40](.assets_IMG/MatrixTheory/IMG_20231005-195751890.png)  
对于复数空间V，数域F也是复数的情况，V中1和i是线性相关的，所以其基为1，维数为1。
![picture 41](.assets_IMG/MatrixTheory/IMG_20231005-200354404.png)  
这里的$V=R^+,F=R$，其中$\oplus$和$\circ$运算是自定义的，对于这种情况。基不能是1，因为前面证明过，1是这个空间中的0元素。前面也证明过，这个空间中，采用$\oplus$和$\circ$这两种运算，其他任意实数之间也是可以相互线性表示的，所以可以找个最简单的实数，2，作为其基。  
![picture 44](.assets_IMG/MatrixTheory/IMG_20231005-201052689.png)  
![picture 46](.assets_IMG/MatrixTheory/IMG_20231005-201111638.png)  

这里老师想要证明的是，在V中任意一个向量$\eta$，都可以用它的基来表示。这里板书是通过使用两条定理来证明。
![picture 47](.assets_IMG/MatrixTheory/IMG_20231005-203230093.png)  
如何证明$\beta,\alpha_1,\alpha_2,\cdots,\alpha_n$线性相关，这里使用的是下下张图中的定理。
![picture 48](.assets_IMG/MatrixTheory/IMG_20231005-203913781.png)  
![picture 49](.assets_IMG/MatrixTheory/IMG_20231005-204153670.png)  

这是个证明题，但是有两种证明方法：  
第一种，先证明$f_1,f_2,f_3$三者线性无关，然后再证明$F_3[x]$中的任意一个向量都可以用$f_1,f_2,f_3$三者来表示。  
![picture 50](.assets_IMG/MatrixTheory/IMG_20231005-210923063.png)  
第二种，直接用上面的定理，先证明$dimF_3[x]=3$，然后再证明$f_1,f_2,f_3$三者线性无关，再根据定理，即可证明$f_1,f_2,f_3$这三个向量可以构成一组基。  
![picture 51](.assets_IMG/MatrixTheory/IMG_20231005-211143510.png)  
![picture 52](.assets_IMG/MatrixTheory/IMG_20231005-211942065.png)  

## 1.2.3 定义(坐标)
注意，在线性空间中基是有顺序的，如果顺序如图一样颠倒了，那么坐标表示也会被颠倒。  
![picture 53](.assets_IMG/MatrixTheory/IMG_20231006-104408009.png)  
![picture 54](.assets_IMG/MatrixTheory/IMG_20231006-105200168.png)  

其中定理1是很显然的。前者$\eta=\theta$表示的是在抽象线性空间中的0向量。后面的$X=\theta$则表示在这个抽象的线性空间中，$\eta$如何通过该线性空间中的基$\alpha_1,\alpha_2,\cdots,\alpha_n$坐标表示。也就是说$X$就是我们在线性代数中所理解的坐标$(0,0,\cdots,0)$。  
![picture 56](.assets_IMG/MatrixTheory/IMG_20231006-112540107.png)  
定理2，老师在视频中证明了充分性，通过举例，由$\eta=k_1\eta_1+k_2\eta_2$推导出$X=k_1X_1+k_2X_2$。
![picture 57](.assets_IMG/MatrixTheory/IMG_20231006-113445560.png)  
为什么要有基和坐标这样的概念，是因为可以方便的将抽象线性空间$V$下的向量关系转化为$F^n$下的坐标的关系。这种其实放在之前的线性代数中很好理解，因为在之前的线性代数中，向量就是用坐标来表示的，向量的线性相关等关系就是通过坐标来体现的。  
![picture 58](.assets_IMG/MatrixTheory/IMG_20231006-133622034.png)  

这里例子里用的就是上述定理，将判断向量的线性相关性，转化成了判断坐标的线性相关性。  
![picture 59](.assets_IMG/MatrixTheory/IMG_20231006-140813635.png)  
这个例子里也是利用了上述定理，将2x2的矩阵转化成了坐标，然后对应坐标的极大无关组也就是对应矩阵的极大无关组。  
![picture 60](.assets_IMG/MatrixTheory/IMG_20231006-143639353.png)  

# 06 线性空间与线性变换(3) P054-070
## 1.2.4 形式记号
形式记号，下图就是下下张图中的推导。这里的$\alpha$只是一种表示方式或者说形式记号，可能有很多种形式，各种向量空间的基，表示方式都不太一样。  
![picture 61](.assets_IMG/MatrixTheory/IMG_20231006-144852210.png)  
![picture 62](.assets_IMG/MatrixTheory/IMG_20231006-144916980.png)  

## 1.2.5 形式记号的性质
下边是三组向量表示关系的简单转化推导。  
![picture 64](.assets_IMG/MatrixTheory/IMG_20231006-155124507.png)  
![picture 65](.assets_IMG/MatrixTheory/IMG_20231006-155137499.png)  

这里是一个命题的充分性和必要性证明  
先证明充分性(用的是反证法)：  
![picture 66](.assets_IMG/MatrixTheory/IMG_20231006-160438069.png)  
再证明必要性(先假设了一个$X$，使得$(\beta_1,\beta_2,\cdots,\beta_n)X=\theta$)：  
![picture 67](.assets_IMG/MatrixTheory/IMG_20231006-161917594.png)  

## 1.2.6 定义(过渡矩阵)
![picture 69](.assets_IMG/MatrixTheory/IMG_20231006-164201080.png)  

这里是两个例子，从自然基到新的基的过渡矩阵。  
![picture 68](.assets_IMG/MatrixTheory/IMG_20231006-164020115.png)  
![picture 70](.assets_IMG/MatrixTheory/IMG_20231006-164505053.png)  

## 1.2.7 过渡矩阵的性质
下面这道题，就不再是求自然基到其他基的过渡矩阵了，而是求两个非自然基之间的过渡矩阵。此时如果直接解方程组死算会很麻烦，但是这里可以使用过渡矩阵的性质。这样就可以计算得，从$\alpha$到$\beta$过渡矩阵就是$A^{-1}B$。  
![picture 71](.assets_IMG/MatrixTheory/IMG_20231006-164923988.png)  

这里是对下面得到的两个公式的一个证明。  
![picture 72](.assets_IMG/MatrixTheory/IMG_20231006-170516762.png)  
这道例题是利用上面的坐标变换公式来计算在新基下的坐标。  
![picture 73](.assets_IMG/MatrixTheory/IMG_20231006-171528987.png)  

## 1.3 子空间 交与和
## 1.3.1 子空间 交与和
这里红色字迹是举了一个例子，虽然下方的运算$\oplus$和$\circ$也能在$F=R$上构成线性空间，但是并不能说W是V的子空间，因为下方的运算是$\oplus$和$\circ$，而上方的运算是正常的$+$和$\bullet$。运算不一样，也不能算是子空间。  
![picture 74](.assets_IMG/MatrixTheory/IMG_20231006-183618418.png)  
![picture 75](.assets_IMG/MatrixTheory/IMG_20231006-205733907.png)  

如果要验证非空子集W是否为V的子空间，只需要验证4条：  
1. 是否满足加法封闭(这里说的封闭就是相加后的结果依旧属于W)
2. 是否满足数乘封闭(这里说的封闭就是数乘后的结果依旧属于W)
3. 是否满足八条法则中的第三条，即0元素也要属于W
4. 是否满足八条法则中的第四条，即负元素也要属于W  

为什么八条运算法则只需要验证三和四，因为其他的运算法则用不到线性运算，在V中成立的，在W中也一定成立。  
![picture 76](.assets_IMG/MatrixTheory/IMG_20231006-211253084.png)  
![picture 55](.assets_IMG/MatrixTheory/IMG_20231006-111339332.png) 

但是上述的验证条件还可以简化，只需要满足前两个即可：  
1. 是否满足加法封闭(这里说的封闭就是相加后的结果依旧属于W)
2. 是否满足数乘封闭(这里说的封闭就是数乘后的结果依旧属于W)  

为什么？下张图中老师进行了证明，因为只要满足数乘，通过乘以0元素和-1就可以发现，0元素和负元素都属于W。  
讲解见视频：P6-45:06
![picture 77](.assets_IMG/MatrixTheory/IMG_20231006-211642192.png)  
这里的线性运算就是指加法和数乘。  
![picture 78](.assets_IMG/MatrixTheory/IMG_20231006-212802542.png)  

0元素和V本身都可以叫V的子空间。这两个空间又可以被称为平凡子空间。  
![picture 79](.assets_IMG/MatrixTheory/IMG_20231006-213147362.png)  

对于下图中的$V_1$，不是$R^3$的子空间，因为如果取$\alpha=(\frac{1}{3},0,0)\in V_1$，则$2\bullet\alpha=(\frac{2}{3},0,0)\notin V_1$，所以不满足数乘运算封闭性。当然，还有一个更简单的验证方式，只需要验证0元素是否属于$V_1$即可。这里很显然不属于，因为0带入不成立。  
而对于$V_2$则一定是子空间，因为很容易验证加法和数乘成立。验证加法，就是两个一样的式子相加后依旧为0。验证数乘就是将等式两边同时乘以一个数，然后等式右边也是0。这两种验证方式，等式都是成立的。  
![picture 80](.assets_IMG/MatrixTheory/IMG_20231006-213259402.png)  
对于这两种子空间，可以很明显的发现，如果等式右边为0，或者该方程对应的平面经过原点，则该子空间是$R^3$的子空间。  
![picture 81](.assets_IMG/MatrixTheory/IMG_20231006-220809055.png)  

## 1.3.2 两类重要的子空间
对于这种齐次线性方程组的解空间，他的基就是他的基础解系，维数就对应了$n-r(A)$。$n-r(A)$实际上也就是基础解系的秩。  
![picture 82](.assets_IMG/MatrixTheory/IMG_20231007-135821576.png)  
对于这种，我的理解，$\alpha_1,\alpha_2,\cdots,\alpha_s$是$V$中的部分向量(但是这部分向量不一定是$V$的极大无关组，因为这里不是要求$V$的基)。  
![picture 83](.assets_IMG/MatrixTheory/IMG_20231007-140334924.png)  

这里的$\alpha_j$就是指$W$的**生成元**。  
![picture 84](.assets_IMG/MatrixTheory/IMG_20231007-141536959.png)  
对于下面这个命题的证明。证明充分性，老师用的是第一条命题的结论。证明必要性，老师是分别证明$L(\alpha_1,\alpha_2,\cdots,\alpha_s)\subseteq L(\beta_1,\beta_2,\cdots,\beta_t)$和$L(\alpha_1,\alpha_2,\cdots,\alpha_s)\supseteq L(\beta_1,\beta_2,\cdots,\beta_t)$。视频讲解：P06-1:01:20  
![picture 85](.assets_IMG/MatrixTheory/IMG_20231007-142048713.png)  
第三条命题应该显而易见，证明见视频讲解：P06-1:04:25  
![picture 86](.assets_IMG/MatrixTheory/IMG_20231007-143536778.png)  

这个例题应该很简单。  
![picture 87](.assets_IMG/MatrixTheory/IMG_20231007-143949768.png)  

这里将ABCD矩阵转换成对应的坐标，求出对应坐标的极大无关组就是W的基。  
![picture 88](.assets_IMG/MatrixTheory/IMG_20231007-150255538.png)  

这里例子中，老师几乎是用观察法得到的，然后再证明矩阵$A$和$B$是不是基。  
![picture 89](.assets_IMG/MatrixTheory/IMG_20231007-151623136.png)  

证明是子空间，只要证明加法封闭，数乘封闭即可。
1. 证明加法封闭就是证明$X_1+X_2\in W$，因为$W=\{X\in F^{2\times2}|AX=XA\}$，所以只需要证明$X_1+X_2$与$A$可交换，就说明$X_1+X_2\in W$。
2. 证明数乘封闭就是在$AX=XA$两边同乘$k$，所以一定是满足的。

![picture 90](.assets_IMG/MatrixTheory/IMG_20231007-162223073.png)  
这里是将A矩阵拆成了$\begin{pmatrix}
0 & 0 \\
2 & 0
\end{pmatrix}$和一个单位矩阵相加，因为单位矩阵跟谁都是可交换的，所以只要验证$\begin{pmatrix}
0 & 0 \\
2 & 0
\end{pmatrix}$与A可交换就可以了。  
这里相当于是使用了待定系数法，将$X$中各个位置的代数关系确定好，然后再利用观察法同上面的例子一样，得到$W$的基。  
![picture 91](.assets_IMG/MatrixTheory/IMG_20231007-193050357.png)  
![picture 92](.assets_IMG/MatrixTheory/IMG_20231007-193141216.png)  

# 07 线性空间与线性变换(4) P072-
## 1.3.3 子空间的交与和
在平面上，如果直线经过坐标原点，也构成子空间。相应的，如果空间中的平面经过平面也构成子空间。  
下图中的$V_1\bigcup V_2$，不是平面的子空间，因为$V_1\bigcup V_2$加法不封闭，也就是说在$V_1$和$V_2$上分别取一个向量，但是相加后的结果，并不落在$V_1\bigcup V_2$上，所以加法不封闭，不是子空间。  
![picture 93](.assets_IMG/MatrixTheory/IMG_20231008-222255299.png)  

交与和是有区别的，和比交更大，并且包含了交。  
![picture 19](.assets_IMG/MatrixTheory/IMG_20231011-220412929.png)  

这里是在证明这个命题的正确性，如图老师笔记，是证明了左边包含于右边。  
![picture 94](.assets_IMG/MatrixTheory/IMG_20231020-134150462.png)  

## 1.3.4 维数定理
![picture 95](.assets_IMG/MatrixTheory/IMG_20231020-170003126.png)  

如图所示，对于$V_1$和$V_2$的基可以直接观察法得到，维数自然也就能得到了。
![picture 96](.assets_IMG/MatrixTheory/IMG_20231020-170603495.png)  
这里老师几乎是用观察法来求$V_1\cap V_2$的具体表达式，然后根据式子$V_1\cap V_2=\left \{ \begin{pmatrix} x & x \\ -x & -x \end{pmatrix} |\ x\in F \right \}$又可以观察出来其基为$\begin{pmatrix} 1 & 1 \\ -1 & -1 \end{pmatrix}$，所以维数就是1维。  
视频：P7-13:22
![picture 98](.assets_IMG/MatrixTheory/IMG_20231020-193212686.png)  

这道题中如果是计算$V_1+V_2$的基和维数，就直接将$\alpha_1,\alpha_2,\beta_1,\beta_2$四个向量组合成一个矩阵，然后算极大线性无关组即可。如果是计算$V_1\cap V_2$的基，就需要列式$\eta=k_1\alpha_1+k_2\alpha_2=l_1\beta_1+l_2\beta_2$，此时就看$k_1\alpha_1+k_2\alpha_2=l_1\beta_1+l_2\beta_2$有几种类型的组合，因为这里方程$k_1\alpha_1+k_2\alpha_2-l_1\beta_1-l_2\beta_2=0$的基础解系只有一个，所以也就是说$k_1\alpha_1+k_2\alpha_2=l_1\beta_1+l_2\beta_2$只有一种类型的组合，也就是说$\eta=k_1\alpha_1+k_2\alpha_2=l_1\beta_1+l_2\beta_2$中的$\eta$也就只有一种，所以$V_1\cap V_2$的基也就只有一个，维数也就是1。当然这里$V_1\cap V_2$的维数也可以用维数定理来算，也就是$dim(V_1\cap V_2)=dimV_1+dimV_2-dim(V_1+V_2)$，计算得$dim(V_1\cap V_2)=2+2-3=1$。
![picture 20](.assets_IMG/MatrixTheory/IMG_20231023-165120709.png)  
![picture 21](.assets_IMG/MatrixTheory/IMG_20231023-165501256.png)  

这道题计算$V_1\cap V_2$的基和维数比较简单，这里要算的$\eta$就是$V_1\cap V_2$中的，相当于既要满足$A\eta=\theta$，又要满足$B\eta=\theta$。这里直接将矩阵A和B纵向组合成一个大的矩阵，然后解方程组就可以了。相当于就是求公共解。  
如果是计算$V_1+V_2$的基和维数，就要分别计算$V_1$和$V_2$的生成元，然后再通过上一题类似的方式，将所有生成元组合成一个矩阵，然后算极大线性无关组。  
![picture 22](.assets_IMG/MatrixTheory/IMG_20231023-172410985.png)  

## 1.3.5 直和
![picture 23](.assets_IMG/MatrixTheory/IMG_20231023-212923176.png)  
老师这里是想通过1推出2，2再推出3，3推出4，4推出3，3推出1。
![picture 24](.assets_IMG/MatrixTheory/IMG_20231023-213022720.png)  

其中1为什么能推出2？是因为，根据直和定义，只要满足1，那么2就一定满足，因为表示唯一，包括0向量表示也唯一。  
![picture 25](.assets_IMG/MatrixTheory/IMG_20231023-213141939.png)  
其中2为什么能推出3？假设$\eta\in V_1\cap V_2$，那么也就显然$\eta\in V_1$，如果要表示0向量，就要找一个$-\eta\in V_2$，但是因为2中说了，0向量表示唯一，也就是说$\eta$只能是0向量了。  
![picture 26](.assets_IMG/MatrixTheory/IMG_20231023-214548920.png)  
其中3为什么能推出4？是利用的维数定理，很显然。$dim(V_1+V_2)=dimV_1+dimV_2-dim(V_1\cap V_2)$，其中$dim(V_1\cap V_2)=0$。  
同理4推出3，也是维数定理。  
其中3为什么能推出1？这里老师的做法很巧妙。见下图中绿框部分。  
视频讲解：P07-34:57  
![picture 27](.assets_IMG/MatrixTheory/IMG_20231023-220745823.png)  
其中4为什么能推出5？这里很显然，然后老师也就没有讲。  
至于如何判断两个子空间的和空间是不是直和，用的最多的是第3个和第4个条件。  
![picture 28](.assets_IMG/MatrixTheory/IMG_20231023-221226545.png)  

在这个例子中，最终要证明的是$F^{n\times n}=V_1\oplus V2$，然后这个证明可以拆解成两个证明过程，第一个是证明$V_1+V_2$是直和，第二个是证明$F^{n\times n}=V_1+V_2$。  
视频讲解：P07-39:10  
其中证明$V_1+V_2$是直和，直接用的是题目中的条件。  
证明$F^{n\times n}=V_1+V_2$，就是要证明$F^{n\times n}\subseteq V_1+V_2$和$F^{n\times n}\supseteq V_1+V_2$。其中$F^{n\times n}\supseteq V_1+V_2$是显然成立的，然后证明$F^{n\times n}\subseteq V_1+V_2$，也就是说，只要证明任意一个$n\times n$的矩阵，都可以写成对称矩阵和反对称矩阵的和。至于这个对称矩阵和反对称矩阵分别是什么，见下图中红框部分。红框中的左边是对称阵，右边是反对称阵。  
![picture 29](.assets_IMG/MatrixTheory/IMG_20231023-223049873.png)  

视频讲解：P07-41:23  
![picture 30](.assets_IMG/MatrixTheory/IMG_20231026-215522109.png)  

## 1.3.6 多个子空间的直和
![picture 32](.assets_IMG/MatrixTheory/IMG_20231026-215848908.png)  
下面两张截图要说明的是对于等价的第三个条件，如果改成下图中下方的红圈部分，是不行的，因为两两相交为零向量的条件不够强。老师用三维空间中的直角坐标系举了一个例子，可以看到如果仅仅满足两两相交为零向量，并不是直和。
讲解：P07-46:30  
![picture 33](.assets_IMG/MatrixTheory/IMG_20231026-220231270.png)  
![picture 34](.assets_IMG/MatrixTheory/IMG_20231026-221423029.png)  

# 08 线性空间与线性变换(5)

# 09 线性空间与线性变换(6)

# 10 内积空间、等距变换(1)

# 11 内积空间、等距变换(2)

# 12 矩阵的相似对角性(1)

# 13 矩阵的相似对角性(2)

# 14 矩阵的相似对角性(3)

# 15 矩阵的相似对角性(4)

# 16 矩阵的相似对角性(5)

# 17 Hermite二次型(1)

# 18 Hermite二次型(2)

# 19 Hermite二次型(3)

# 20 范数及矩阵函数(1)

# 21 范数及矩阵函数(2)

# 22 矩阵的广义逆
