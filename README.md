# OOP

* 教授：劉興民 教授
* 時間：大一下(大二下課程）
* 語言：C++14


# 目錄
HW1 : 判斷迴文
HW2 : Locate Word

# 內容
## HW1
1. 以 C++ 撰寫 判斷迴文(palindrome)的程式 (40%)

(迴文代表「從左到右」和「從右到左」的字母順序都相同，
例如 A man, a plan, a canal: Panama! 這段文字不論正反都是 A M A N A ...)
你的程式必須用引數(argument)的方式讓使用者輸入一段文字，
判斷這段文字是否為迴文，如果是迴文的話，印出 Yes，否則印出 No。

例如:
使用者輸入 a.out "A man, a plan, a canal: Panama!" 時，程式應該印出 Yes

判斷條件如下: (注意: 這邊的指示和作業投影片稍有不同, 評分以這邊所寫的為準)
(1) 忽略所有的空白和標點符號
　<提示: 我們的測資會把字串用 " " 框起來輸入，並且裡面不會含有引號 (") 或右斜線(\), 
　因此 argument 永遠只會有一個，不需要考慮把輸入的 argument 串在一起的問題>

(2) 不分大小寫 (ex. Aha應該判斷為迴文，即使 大寫A 和 小寫a 不同)

(3) 數字 不論「納入迴文判斷條件」或是「忽略」都給對

助教會用幾組測資來測試同學的程式是否運作正確，分數以測試結果為依據。

2. 以 Java 撰寫 判斷迴文的程式 (35%)

判斷條件和 C++ 的程式相同

3. MakeFile (10%)

請參考 討論區 及 課業倉儲 的 MakeFile 教學連結，自行撰寫 MakeFile 檔案。
MakeFile 只需要針對 C++ 或 Java 其中一個程式撰寫就好，不用兩個都寫。

你的 MakeFile 要跟 source code 放在同一個目錄底下，並且做到:
(1) 當使用者輸入 make 時，可以從你的 source code 編譯出 .out 執行檔 (在 Windows 下是 .exe)
(2) 當使用者輸入 make clean 時，可以把所有的中間檔 (例如 .o) 和執行檔 (.out) 清除。

4. Debugger (15%)

請利用 debugger 執行以下 7 個指令，並截圖附在作業檔案中。
GDB(C++) 或 JDB(Java) 擇一使用即可，如果你要使用 LLDB、Visual Studio 或 VSCode 也可以接受。

(1)印出程式碼
(2)設定breakpoint
(3)向下執行程式碼(直到breakpoint)
(4)向下執行一行程式碼
(5)印出特定變數值(ex: 變數a現在的值)
(6)設定持續印出某變數值
(7)結束debugger


## HW2
以 C++ 或 Java 擇一撰寫即可。

1. 啟動程序時，顯示 > 符號 或 適當文字 來提示使用者輸入(2%)

2. load (15%)
使用者輸入load <filename>時，載入文字檔
例如 load sixpence.txt

3. locate (50%)
使用者輸入locate <word> <n>時，可以查詢 <word> 的第 <n> 次出現是在文章的第幾個單詞。

特殊符號(逗點、句點、問號等)不算作單詞的一部分，
但是單引號(') 算作單詞的一部分，例如 wasn't 應該是一整個單詞。
換句話說，除了單引號、字母、數字之外的所有字元 (" : ; ' [ ] { } _ = + - * % / \ ~ ` 等)，都不算作單詞的一部分。

數字的處理方式以「是否有空格斷開」判斷:
如 Hello 123 world，123 算是第2個單詞。
Hello 123world，123world 算是第2個單詞。

locate 不區分大小寫 有區分大小寫 (註: 由於投影片上寫 case sensitive, 我們依照投影片上的指示來做)
(當使用者要找 Flower 時，你的程式應該要能找到 Flower，但不應該找到 flower)

＊ 提示: 由於這次的程式會讓使用者輸入指令，請加上適當的「防呆措施」。
(例如使用者輸入 "locate pie pppp" 或 "locate pie -2" 時，程式不能當掉。)

4. new(5%)
使用者輸入 new 時會重置單詞列表(把單詞列表清空)，讓使用者可以重新 load 文件一次。

5. end(2%)
使用者輸入end會中止程式

6.錯誤提示 (16%)
(1) locate 找不到單詞時顯示 No matching entry
命令有區分大小寫 (也就是說，你的程式只需要處理 locate，而不用處理 Locate、locate、loCATE、...)
(2) 輸入錯誤或無關指令(例如: find word 7) 顯示 ERROR: Invalid command
(3) load 文字檔時，如果找不到檔案(或是無法讀取) 則提示 ERROR: Error reading from file。
如果找不到檔案，則提示 ERROR: File not found
讀取錯誤則提示 ERROR: Error reading from file

7. MakeFile (10%)
請參考 討論區 及 課業倉儲 的 MakeFile 教學連結，自行撰寫 MakeFile 檔案。

你的 MakeFile 要跟 source code 放在同一個目錄底下，
並且當使用者輸入 make 時，可以從你的 source code 編譯出執行檔。
