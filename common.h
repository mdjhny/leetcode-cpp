//
// Created by yangfanxin on 18/9/28.
//

#ifndef LEETCODE_CPP_COMMON_H
#define LEETCODE_CPP_COMMON_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <list>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>

/**
 * 打印数组
 * @tparam T
 * @param os
 * @param v
 * @return
 */
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << '[';
    std::copy(v.begin(), v.end(), std::ostream_iterator<T>(os, ","));
    // 删除最后一个多余的逗号
    if (!v.empty())
    {
        os << '\b';
    }
    os << ']';
    return os;
}

/**
 * 打印嵌套数组
 */
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<std::vector<T>> &v)
{
    os << '[';
    for (const auto &i : v)
    {
        std::ostringstream ss;
        ss << i;
        os << ss.str() << ',';
    }
    if (!v.empty())
    {
        os << '\b';
    }
    os << ']';
    return os;
}

typedef int elem_t;
// 单链表
struct ListNode
{
    elem_t val;
    ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

std::ostream &operator<<(std::ostream &os, ListNode *l)
{
    while (l)
    {
        os << l->val << "->";
        l = l->next;
    }
    os << "NULL";
    return os;
}

// vector转化为单链表
ListNode *make_list(std::vector<elem_t> &v)
{
    if (v.empty())
    {
        return nullptr;
    }
    ListNode *head = nullptr;
    ListNode *p = nullptr;
    for (int i : v)
    {
        if (head == nullptr)
        {
            head = p = new ListNode(i);
        }
        else
        {
            p->next = new ListNode(i);
            p = p->next;
        }
    }
    return head;
}

ListNode *make_list(std::initializer_list<elem_t> list)
{
    if (list.size() == 0)
    {
        return nullptr;
    }
    ListNode *head = nullptr;
    ListNode *p = nullptr;
    for (auto elem : list)
    {
        if (head == nullptr)
        {
            head = p = new ListNode(elem);
        }
        else
        {
            p->next = new ListNode(elem);
            p = p->next;
        }
    }
    return head;
}

// 二叉树
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
//
std::ostream &operator<<(std::ostream &os, TreeNode *t)
{
    if (!t)
    {
        os << "NULL";
        return os;
    }
    // 借助队列，在进行按层遍历时，记录遍历的层数即可
    std::queue<TreeNode *> q;
    q.push(t);
    int depth = 0;
    while (!q.empty())
    {
        size_t node_cnt = q.size();
        for (size_t i = 0; i < node_cnt; ++i)
        {
            auto node = q.front();
            if (node)
            {
                os << node->val << ',';
            }
            else
            {
                os << "null,";
            }
            // 左子树和右子树先后入队列，层序遍历
            q.pop();
            // 左右子树必须至少一个不为空，即当探测到节点为非叶子节点才继续插入空节点到队列
            // 防止最后打出一长串 null
            if (node && (node->left || node->right))
            {
                if (node->left)
                {
                    q.push(node->left);
                }
                else
                {
                    q.push(nullptr);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
                else
                {
                    q.push(nullptr);
                }
            }
        }
        // 当前层节点全都遍历完成后，层数加1
        ++depth;
    }
    os << '\b';
    return os;
}

// 打印变量的辅助工具
#define PVAR(x)                                  \
    do                                           \
    {                                            \
        std::cout << #x "=" << (x) << std::endl; \
    } while (0)

// io流加速，减少耗时
static int x = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return 0;
}();

#endif //LEETCODE_CPP_COMMON_H
