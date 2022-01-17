*** 如果工作站上 make 不成功的話，可以用 gmake 試試看 (可能是 .ifdef 指令造成的問題)

1. C++ 迴文 (35%)

* 測試資料: 每一個測資錯扣 7 分
1 → 1
2 → 1
3 → 2
50 → 12586269025
90 → 2880067194370816120
97 → 83621143489848422977 (錯了不扣，對了+10)



2. Java(30%)
測試資料同 C++，每一個測資錯扣 6 分

3. MakeFile(20%):
測試 gmake 是否可以成功編譯，以及 gmake clean 是否可以成功清除。
如果 gmake 失敗的話最多扣 15 分，沒有做 clean 扣 5 分。(don't know how to make clean)
如果 make clean 提示找不到 del 指令的話，，暫不扣分。
如果 makefile 只有處理到 Windows 的部分(只會編譯出 .exe)，暫不扣分。

4. Debugger (15%):
GDB　截圖應該包含以下 7 個指令, 如果用其他的 debugger 請自行判斷
少 list 扣 3%，其他一個指令扣 2%

list(l)
break(b)
run(r)
next(n) 或 continue(c)
print(p)
display
quit(q)