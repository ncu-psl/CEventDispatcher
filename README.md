# C-Event-Dispatcher

## 介紹

C Event Dispatcher 是一個C語言事件驅動程式設計輔助工具，提供條件判斷式事件分配器，讓使用者可以使用條件判斷式做事件處理器的觸發設定。

## 使用語言

* C

## 環境

* gcc ( Ubuntu 7.3.0 )
* bison ( GNU Bison, version：3.0.4 )
* flex ( version：2.6.4 )
* ncurses (使用於範例1)

## 如何建置

``` sh
git clone git@github.com:ncu-psl/CEventDispatcher.git

# 建立 C Event Dispatcher 工具 libCED.a
# 建立的 libaray 目標位置：CEventDispatcher/output
cd CEventDispatcher
make

# 使用 GCC 編譯自己的程式
gcc my_program.c CEventDispatcher/output/libCED.a
```

## 使用說明

``` c
#include <CEventDispatcher/src/CED.h>

/*
Dispatcher( Name );
建立分配器
參數
    Name：事件處理器名稱
*/
Dispatcher( KeyBoardHandler );

/* 
add(&dispatcher, &function, expression);
加入事件處理器
參數
    &dispatcher：指定事件分配器
    &function：執行的動作
    expression：觸發處理器的條件判斷式
*/
add(&KeyBoardHandler, printInput, input > 'a' && input < 'z');

/*
run(&dispatcher, array);
將事件佇列傳遞至 dispatcher
參數
    &dispatcher：指定事件分配器
    array：事件訊息佇列 (int 型態)
*/
run(&KeyBoardHandler, input);
```

## 範例程式

* [範例1 鍵盤輸入處理 with switch-case](https://github.com/ncu-psl/CEventDispatcher/blob/master/example/GetKeyboardState.c)
  
    ``` sh
    # 需ncurses支援
    make ex1_KeyboardEvent
    ```

* [範例2 鍵盤輸入處理 with CED](https://github.com/ncu-psl/CEventDispatcher/blob/master/example/ex2_KeyboardCED.c)

    ``` sh
    make ex2_KeyboardCED
    ```

* [範例3 紅綠燈範例](https://github.com/ncu-psl/CEventDispatcher/blob/master/example/ex3_TrafficLight.c)

    ``` sh
    make ex3_TrafficLight
    ```

* [範例4 咖啡販賣機FSM範例1](https://github.com/ncu-psl/CEventDispatcher/blob/master/example/ex4_VendingMachine.c)

    ``` sh
    make ex4_VendingMachine1
    ```

* [範例5 咖啡販賣機FSM範例2](https://github.com/ncu-psl/CEventDispatcher/blob/master/example/ex5)

    ``` sh
    make ex5_VendingMachine2
    ```
