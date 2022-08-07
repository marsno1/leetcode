#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    long long val;
    int index; // 在原始数组中的下标
    int prev;
    int next;
};

int main() {
    int n;
    cin >> n;
    vector<int> pointers(n + 2); // 间接指针数组：从原始数组下标映射到排序数组下标
    vector<Node> sortedArray(n + 2); //排序数组
    // 哨兵节点：它们与任意一个元素的差的绝对值，都应该大于任意两个元素的差的绝对值
    sortedArray[0].val = -3e9 - 1, sortedArray[0].index = 0;
    sortedArray[n + 1].val = 3e9 + 1, sortedArray[n + 1].index = n + 1;
    // 1.初始化输入数组，记录原始下标
    for (int i = 1; i <= n; ++i) {
        cin >> sortedArray[i].val;
        sortedArray[i].index = i;
    }
    // 2.按元素的值排序
    sort(sortedArray.begin(), sortedArray.end(), [](const Node & a, const Node & b) {
        return a.val < b.val;
    });
    // 3.构建双向链表，和间接指针数组
    sortedArray[0].next = 1, sortedArray[n + 1].prev = n;
    for (int i = 1; i <= n; ++i) {
        sortedArray[i].prev = i - 1;
        sortedArray[i].next = i + 1;
        int index = sortedArray[i].index;
        pointers[index] = i;
    }
    
    vector<pair<long long, int>> ans(n + 1);
    // 4.按输入元素的相反顺序，逐个删除链表中的节点
    for (int index = n; index >= 2; --index) {
        int i = pointers[index];
        int prev = sortedArray[i].prev, next = sortedArray[i].next;

        if (sortedArray[i].val - sortedArray[prev].val <= sortedArray[next].val - sortedArray[i].val) {
            ans[index].first = sortedArray[i].val - sortedArray[prev].val;
            ans[index].second = sortedArray[prev].index;
        } else {
            ans[index].first = sortedArray[next].val - sortedArray[i].val;
            ans[index].second = sortedArray[next].index;
        }
        // 删除节点i
        sortedArray[prev].next = next;
        sortedArray[next].prev = prev;
    }
    for (int i = 2; i <= n; ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}
