# 競技プログラミング用のテンプレート

## c++ メモ
競技プログラミングでのc++の小技をメモしていく
### 1. next_permutation
cf) [Qiita記事](https://qiita.com/siser/items/a91022071b24952d27d9)

順列を辞書順に書き換えていく(文字列でも可)

使用方法
```
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v={1,2,3,4};
    do{
        for(int i=0; i<4; i++){
            cout<<v[i];
            if(i!=3)cout<<" ";
        }
        cout<<endl;
    }while(next_permutation(v.begin(),v.end()));
    return 0;
}
```
結果
```
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
//...(順列が生成されるが長いので割愛)
4 3 1 2
4 3 2 1
```

逆順生成でprev_permutationもある

### 2. printf
- long long intのprint
```
#include <stdio.h>

int main() {
    long long int a = (long long int)1 << 63;

    // long long intとして表示 (印字対象データの最上位ビットが立っているので負数とみなされる)
    printf( "case3: %lld\n", a );

    // unsigned long long intとして表示
    printf( "case4: %llu\n", a );

    // 16進数で表示
    printf( "case5: 0x%llx\n", a );
}
```
結果
```
case3: -9223372036854775808
case4: 9223372036854775808
case5: 0x8000000000000000
```

### 3. bitset
```
bitset<10>
// 0000000000を扱える
// biset<n>で0(n/64)の計算量で扱える
```
### 4. 重複要素削除
uniqueは隣接する重複要素を削除し、vectorの長さを変化させないので末尾にゴミが残る(O(n))
そこで以下のようにすることでuniqueなvectorとなる
sortのO(nlogn)の計算量
```
std::sort(vec.begin(), vec.end());
vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
```

### 5. 立っているbitのcount
```
__builtin_popcount(<int>)
__builtin_popcountll(<long long int>)
```

### 6. main内での関数作成
```
auto function = [&]() {
    return ;
};
```

### 7. multisetでのerase
```
multiset<int> S;
S.insert(1); S.insert(1);
S.erase(1); // 1の要素を全削除
S.size(); // 0

// 1要素のみ削除するには
multiset<int> S;
S.insert(1); S.insert(1);
S.erase(S.find(1));
S.size(); // 1

// 最大, 最小のitrを取得
it = S.begin(); // 最小
it = S.rbegin(); // 最大
```

### 8. 掛け算のoverflow判定
```
long long a, b, INF;
if ((long double)a * (long double)b < INF) {

}
```
