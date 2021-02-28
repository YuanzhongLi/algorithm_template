### extgcd
[リンク1](./extend_gcd.cpp)  
[リンク2](./extend_gcd2.cpp)  
逆元を求めることにも使用可能
Ax ≡ B mod Mとなる最小のxを元めるという問題は
1. d = gcd(A,B,M)としてA/=d, B/=d, M/=dに置き換え、Ax ≡ 1 mod Mの問題に帰着
2. gcd(A,M) != 1のとき逆元がないので解なし
3. gcd(A,M) == 1のとき、(modinv(A)*B+M)%Mが解

### crt
[リンク](./crt.cpp)  
同じ長さ(n)の配列r, mに対して  
x ≡ ri (mod mi)  
となる連立線形合同式を解く
答えは(存在するならば) y,z(0 <= y < z = lcm(mi)) を用いて x ≡ y (mod z) の形で書けることが知られており、この (y,z) をpairとして返します。
答えがない場合は(0,0)を返します。n=0のときは(0,1)を返します。

##### 制約
1 <= mi
lcm(mi) <= long long max

##### 計算量
O(nloglcm(mi))
