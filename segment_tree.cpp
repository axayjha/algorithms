#include <iostream>
using namespace std;

struct Node {
        int data;
        struct Node* left;
        struct Node* right;
};

struct Node* node = (struct Node*)malloc(sizeof(struct Node));

void _build(int *arr, struct Node* node, int start, int end) {
        if (start == end) {                
                node->data = arr[start];
        } else {
                int mid = (start + end) / 2;
                node->left = (struct Node*)malloc(sizeof(struct Node));                
                node->right = (struct Node*)malloc(sizeof(struct Node));
                _build(arr, node->left, start, mid);
                _build(arr, node->right, mid+1, end);
                node->data = node->left->data + node->right->data;
        }
}

void _update(int *arr, struct Node* node, int start, int end, int index, int value) {
        if (start == end) {
                arr[index] = value;
                node->data = value;
        } else {
                int mid = (start + end) / 2;
                if (start <= index && index <= mid)
                        _update(arr, node->left, start, mid, index, value);
                else 
                        _update(arr, node->right, mid+1, end, index, value);
                node->data = node->left->data + node->right->data;         
        }
}

int _query(struct Node* node, int start, int end, int l, int r) {
        if (r < start || end < l)
                return 0;
        else if (l <= start && end <= r)
                return node->data;
        int mid = (start + end) / 2;
        int p1 = _query(node->left, start, mid, l, r);
        int p2 = _query(node->right, mid+1, end, l, r);
        return p1 + p2;
}

void update(int *arr, int n, int index, int value) {
        _update(arr, node, 0, n-1, index, value);
}

void build(int *arr, int n) {
        _build(arr, node, 0, n-1);
}

int query(int n, int l, int r) {
        return _query(node, 0, n-1, l, r);
}

int main(int argc, char const *argv[])
{       
        int arr[6] = {5, 7, 2, 8, 1, -1};
        int n = sizeof(arr)/sizeof(arr[0]);
        build(arr, n);
        cout << query(n, 0, 2) << endl;
        cout << query(n, 1, 3) << endl;
        update(arr, n, 3, 10);
        cout << query(n, 1, 3) << endl;   
        cout << query(n, 4, 5) << endl;               
        return 0;
}
