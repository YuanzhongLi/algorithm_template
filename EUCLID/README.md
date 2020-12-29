### extgcd
[リンク](./extend_gcd.cpp)
逆元を求めることにも使用可能
Ax ≡ B mod Mとなる最小のxを元めるという問題は
1. d = gcd(A,B,M)としてA/=d, B/=d, M/=dに置き換え、Ax ≡ 1 mod Mの問題に帰着
2. gcd(A,M) != 1のとき逆元がないので解なし
3. gcd(A,M) == 1のとき、(modinv(A)*B+M)%Mが解
