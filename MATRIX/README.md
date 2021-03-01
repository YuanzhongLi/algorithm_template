### 一般のm項間漸化式
code cf) [matrix.cpp](./matrix.cpp)

```math
a_{n+m} = \sum_{i=0}^{m-1}b_{i}a_{n+i}
```
とすると、行列を用いて

```math
\begin{bmatrix}
a_{n+m} \\
a_{n+m-1} \\
... \\
a_{n+1}
\end{bmatrix}
=
\begin{bmatrix}
b_{m-1} & ... & b_{1} & b_{0}\\
1 & ... & 0 & 0\\
\vdots & \ddots & \vdots & \vdots\\
0 & ... & 1 & 0
\end{bmatrix}
\begin{bmatrix}
a_{n+m-1} \\
a_{n+m-2} \\
... \\
a_{n}
\end{bmatrix}
```
となり、この行列をn乗することで$a_{n+m}$が求まる。
計算量は$O(m^3logn)$

ただし定数項がある場合は、cを定数項として
```math
\begin{bmatrix}
a_{n+m} \\
a_{n+m-1} \\
... \\
a_{n+1} \\
1
\end{bmatrix}
=
\begin{bmatrix}
b_{m-1} & ... & b_{1} & b_{0} & c\\
1 & ... & 0 & 0 & 0\\
\vdots & \ddots & \vdots & \vdots & \vdots\\
0 & ... & 1 & 0 & 0 \\
0 & ... & 0 & 0 & 1
\end{bmatrix}
\begin{bmatrix}
a_{n+m-1} \\
a_{n+m-2} \\
... \\
a_{n} \\
1
\end{bmatrix}
```

### Matrix Power Series
code cf) [Matrix_Power_Series.cpp](./Matrix_Power_Series.cpp)

制約
* $1 \leq n \leq 30$
* $1 \leq k \leq 10^9$
$A=n\times n$行列
$A+A^2+A^3+...+A^k$を求める

$S_{k} = I + A + ... + A^{k-1}$とすると、

```math
\begin{pmatrix}
A^k \\
S_k
\end{pmatrix}
=
\begin{pmatrix}
A & 0 \\
I & I
\end{pmatrix}
\begin{pmatrix}
A^{k-1} \\
S_{k-1}
\end{pmatrix}
=
\begin{pmatrix}
A & 0 \\
I & I \\
\end{pmatrix}^k
\begin{pmatrix}
I \\
0
\end{pmatrix}
```
よって$\begin{pmatrix} A & 0 \\ I & I\end{pmatrix}^k$を求めることで$S_k$が求まる。

### Mod Matrix
[Mod_Matrix.cpp](./Mod_Matrix.cpp)  
