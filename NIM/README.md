### Nim
###### 問題
石の山がn個あって、それぞれxi個の石がある。A君B君の2人は交互に空でない山を一つ選び、そこから一つ以上の石を取る。A君の番から始まり、最後の石を取った方が勝ちのときどちらが勝つか？

```
x1 XOR x2 XOR ... XOR xn ≠ 0 -> win状態
x1 XOR x2 XOR ... XOR xn = 0 -> lose状態
```

理由
- lose -> win
XORが0のときどれかの山から一つとるとXORが0でなくなる

- win -> lose
XORの一番上のbitが立っている山の、その一番上のbit以下が反転したように取るとXORが0になる

### Grundy数
今の状態から一手で行ける状態のGrundy数に含まれない最小の非負整数が今の状態のGrundy数  
-> 動的計画法で小さいものから求められる
※ Nimと異なりGrundy数は増え得る。そのためループする場合は引き分け  

##### 問題
任意ではなくa1, a2, ... , ak個のどれかしか取れない
```
grundy(x1) XOR grundy(x2) XOR ... XOR grundy(xn) ≠ 0 -> win状態
grundy(x1) XOR grundy(x2) XOR ... XOR grundy(xn) = 0 -> lose状態
```

cf) [code](./grundy.cpp)
cf) [tenkei_031](https://atcoder.jp/contests/typical90/submissions/24636340)
