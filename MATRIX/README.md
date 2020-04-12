## 一般のm項間漸化式

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
