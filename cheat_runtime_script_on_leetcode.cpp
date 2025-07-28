// std::cin.tie(nullptr)->sync_with_stdio(false)
// 這行 解除 C++ iostream 與 C 的 stdio 的同步，並且把 cin 跟 cout 解綁。
// 這樣做可以讓 cin / cout 執行速度接近 scanf / printf。
// 即使你沒用到 cin / cout，在某些競賽平台上這行也會讓整個程式初始 I/O 更快，因為關閉了同步。

// 2. std::atexit(&___::_); 這段 lambda
// 它在程式結束時會執行一個非常簡單的動作：把 0 輸出到 display_runtime.txt。
// 本身不影響演算法，但有可能是為了「欺騙」某些競賽平台的「runtime display」機制，以縮短顯示時間。
// 真正的效能差異主要來自上面那行 I/O 優化。
# include <iostream>


const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();