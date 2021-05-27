# Algorithm template for competitive programming

### EUCLID
ユークリッドの互助法をまとめたライブラリ
[詳細](./EUCLID/README.md)

### MATRIX
行列を扱うライブラリ
[詳細](./MATRIX/README.md)

### MOD
modを扱うライブラリ  
### POINT
幾何計算を扱うためのライブラリ

### TREE
木について

##### 1. MINIMUM_SPANNING_TREE
最小全域木を求める  
[クラスカル法](./MINIMUM_SPANNING_TREE/Kruskal.cpp) を使うと良い  
##### 2. Ancestor
[ancestor.cpp](./TREE/ancestor.cpp)
u, vについてuがvの先祖かどうかを求める  
事前にDFSを行う O(V)
クエリ O(1)

##### 3. LCA
[LCA.cpp](./TREE/LCA.cpp)
u, vの最も近い共通先祖を求める
DFSで親を求めた後、それぞれの頂点について2^k個先の先祖を求める O(V + VlogV)
クエリ O(logN)

### GaussJordan
連立方程式をとく  
[GaussJordan.cpp](./GaussJordan.cpp)  
計算量 O(N^3)  

### その他
##### 1. XorとAnd
a+b - (a xor b) = 2 * (a and b)  
の関係が成り立つ
