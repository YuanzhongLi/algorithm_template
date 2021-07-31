# Algorithm template for competitive programming

### EUCLID
ユークリッドの互助法をまとめたライブラリ
[詳細 (README)](./EUCLID/README.md)

### MATRIX
行列を扱うライブラリ
[詳細 (README)](./MATRIX/README.md)
- [掃き出し法 (README)](./MATRIX/SWEEP_METHOD/README.md)
  - [GaussJordan (Code)](./MATRIX/SWEEP_METHOD/GaussJordan.cpp)
  - [Xor_Sweep (Code)](./MATRIX/SWEEP_METHOD/Xor_Sweep.cpp)

### MOD
modを扱うライブラリ  


### NIM
nimの説明  
grundy数の説明

### POINT
幾何計算を扱うためのライブラリ

### SUFFIX ARRAY
suffix arrayを求める
[詳細 (README)](./SUFFIX_ARRAY/README.md)

### TREE
木について

1. **MINIMUM_SPANNING_TREE**
最小全域木を求める  
[クラスカル法 (Code)](./TREE/MINIMUM_SPANNING_TREE/Kruskal.cpp)を使うと良い  
2. **Ancestor**
[ancestor (Code)](./TREE/ancestor.cpp)
u, vについてuがvの先祖かどうかを求める  
事前にDFSを行う O(V)
クエリ O(1)

3. **LCA**
[LCA (Code)](./TREE/LCA.cpp)
u, vの最も近い共通先祖を求める
DFSで親を求めた後、それぞれの頂点について2^k個先の先祖を求める O(V + VlogV)
クエリ O(logN)
### loop
ある範囲(N)から同じ範囲の数へと変遷するときK回後の結果を求める  
O(N)
[loop (Code)](./loop.cpp)  
他にはO(NlogK)でダブリングを使う手法もある [example](https://atcoder.jp/contests/typical90/submissions/23163310)

### その他
1. **XorとAnd**
a+b - (a xor b) = 2 * (a and b)  
の関係が成り立つ
