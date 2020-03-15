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


