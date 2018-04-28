# OOP

* 教授：劉興民 教授
* 時間：大一下(大二下課程）
* 語言：C++14


# 目錄
* HW1 : 判斷迴文
* HW2 : Locate Word

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

## HW3
<作業內容>
以 C++ 或 Java 擇一撰寫即可。

實作出三個class，分別命名為 Account, User, Transaction，
，以及主程式和 makefile。

內容如下:

1. Account class (20%)
內含ID, amount, deductAmount, amountToTransfer，型態皆為int。 (Account 之間的 ID 不可重複)
AccountOfB：記錄交易對象

constructor:
Account(int amount, int ID) (amount 為帳戶初始金額)

其中包含的函數有:
(1)bool withdraw()：提取一定金額，成功回傳true，否則回傳false
(2)bool deposit()：存入一定金額，成功回傳true
(3)bool transferMoney(Account &AccountOfB, int amountToTransfer)：
把一定金額(amountToTransfer) 轉到另一個帳戶(AccountOfB)
(4)int getAmount()：查詢目前帳戶金額

2. User class (20%)
內含name, ID, account, trans[]。
其中name為一個字串
ID : 型態為int，User 之間的 ID 不可以重複。
account : 上述的 account class
trans[] : 紀錄交易資訊，陣列大小可以自訂。
(提示: 你可以用 array of Transaction pointers 儲存交易資訊，或是利用不同的 constructor 來讓 array 可以成功初始化，
或利用其他資料結構儲存(例如再開一個 class)也可以)

constructor:
User(const char &name[])
你可以視情況自行修正成 只用 const char &input_name，或是改用 pointer 也可以。
(包含 User, Account, Transaction 的 constuctor，都可以自行修改參數類型)

其中包含的函數為:
(1)char *getUsername()： 回傳username
(2)Account &getAccount()：回傳user Account
(3)int getID()：回傳 user ID

3. Transaction class (20%)
內含type, account, amount 三個變數。其中type為一個字串，紀錄交易的類型
amount 為 int，紀錄交易金額。
account 為一個 reference，指向執行交易的 account。

constructor:
Transaction(Account &account, char type[])

其中包含的函數為:
(1)void print()：印出交易詳細資料 


4. 主程式 (30%)
你可以直接利用投影片上的範例，並補上缺少的部分，或是自己寫一個也可以。
你的主程式要執行
(1)存款、提款
(2)轉帳交易，並記錄交易明細(交易的類型、帳戶、金額)
(3)明細查詢 (應列出使用者帳號的交易明細)

5. MakeFile (10%)
請參考 討論區 及 課業倉儲 的 MakeFile 教學連結，自行撰寫 MakeFile 檔案。

你的 MakeFile 要跟 source code 放在同一個目錄底下，
並且當使用者輸入 make 時，可以從你的 source code 編譯出執行檔。

[注意事項]
1.每一個class應該放在單獨的檔案中。
如果你的程式有 ball.cube兩個class的話
你的source code應該要有:
makefile, main.cpp, cube.h, cube.cpp, ball.h, ball.cpp

2.每次執行constructor destructor時，
印出xx constructed, xx destructed (xx為class名稱)

3.所有的member variable都應該設為private,
並讓主程式用public member function去存取或改變member variable。

4.若有作業規定外的功能請附上readme檔，並於檔案內說明。

## HW4
1. Bag class
constructor: (3%)
Bag();
印出Bag constructed
建立一個空的背包
Destructor: (3%)
印出Bag destructed
Copy constructor: (6%)
印出Bag copy constructed
當一個全新的背包被創建為現有背包的copy時，必須分配足夠的節點(node)來保存原始列表的copy。
Assignment operator: (6%)
印出Bag assignment operator
將等號右側的Bag指派給等號左側的Bag時，
等號左側的Bag應為等號右側Bag的複本，等號左側的Bag舊有的值不該存在

其中包含的函數有: (32%)
bool empty() const;
如果背包是空的就回傳true，否則回傳false
int size() const;
回傳背包中物品總數
int uniqueSize() const;
回傳背包中相異物品數
bool insert(const ItemType& value);
將一個物品value加入背包中，成功加入便回傳true
int erase(const ItemType& value);
移除背包中一個物品value，回傳移除的是第幾個物品，若背包中沒這樣物品則回傳0
int eraseAll(const ItemType& value);
移除所有物品value，回傳移除的數量
bool contains(const ItemType& value) const;
如果背包中包含物品value就回傳true，否則回傳false
int count(const ItemType& value) const;
回傳物品value在背包中的數量

Iteration functions: (20%)
走訪背包中物品所需用到的函式
雖然投影片上是寫初始化時用手指指到隨意一個物品，走訪時可以用任意順序走訪，next()要指到相異的物品，
但為了批改方便，大家答案一致，走訪順序就是insert()順序，next()就一路依放入順序指下去，不管是否相異物

void start();
初始化手指，將手指指到第一個物品
若包包為空，印Please input item，並且程式不能壞掉
void next();
將手指指到下一個物品
若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫next()
若還未將手指初始化就呼叫next()，印Please initializes，並且程式不能壞掉
若已經走訪完畢，讓手指不再指向任何物品
bool ended() const;
如果手指沒有指向任何物品就回傳true，否則回傳false
const ItemType& currentValue() const;
回傳手指指到的物品
若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫currentValue()
若還未將手指初始化就呼叫currentValue()，印Please initializes，並且程式不能壞掉
int currentCount() const;
回傳手指指到的是第幾個物品
若更動過背包中的物品(insert, erase, eraseAll)，必須先初始化才能使用呼叫currentCount()
若還未將手指初始化就呼叫currentCount，印Please initializes，回傳0，並且程式不能壞掉

* 注意: Bag中的物品必須用circular doubly-linked list 來連接 (若不是的話，扣30分)
doubly-linked list 包含一個標示「開頭」用的 dummy element，如下圖所示
list.png
list.png (44.04 KiB) 被瀏覽 133 次


* 撰寫 destructor 時請注意把所有的元素刪乾淨，避免 memory leak。 (占 5% 分數)
助教會測試物件 construct 及 destruct 之後的記憶體使用量，來評估是否有 memory leak。

2. non-member functions (20%)
void combine(Bag<ItemType>& bag1, Bag<ItemType>& bag2, Bag<ItemType>& result);
result中有bag1和bag2中的所有東西，bag1和bag2原有的物品不能有任何改變
在這裡就不規定result順序，只要result內物品數量都正確即可
void subtract(Bag<ItemType>& bag1, Bag<ItemType>& bag2, Bag<ItemType>& result);
假設bag1中有n1個"duck", bag2中有n2個"duck",如果n1>n2, 
則result中有n1-n2個"duck"，如果n1<=n2,則result沒有"duck"
在這裡就不規定result順序，只要result內物品數量都正確即可

3. MakeFile (5%)
請參考 討論區 及 課業倉儲 的 MakeFile 教學連結，自行撰寫 MakeFile 檔案。

你的 MakeFile 要跟 source code 放在同一個目錄底下，
並且當使用者輸入 make 時，可以從你的 source code 編譯出執行檔。

[注意事項]
1.附件附上範例用主程式，提供參考，實際測試時會有更多操作

2.你的source code應該要有:
makefile, Bag.h, Bag.cpp, main.cpp

3.所有函式名稱都必須與投影片相同

4.所有的member variable都應該設為private,
並讓主程式用public member function去存取或改變member variable。

5.若有作業規定外的功能請附上readme檔，並於檔案內說明。

