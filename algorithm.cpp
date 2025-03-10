#include <bits/stdc++.h>
using namespace std;

// GCD using Euclidean Algorithm
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Binary Exponentiation
long long binExp(long long a, long long b, long long mod) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
// Iterative Binary Search
int binarySearchIterative(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // Not found
}

// Recursive Binary Search
int binarySearchRecursive(vector<int>& arr, int left, int right, int target) {
    if (left > right) return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binarySearchRecursive(arr, mid + 1, right, target);
    else return binarySearchRecursive(arr, left, mid - 1, target);
}

// Check if a pair exists with a given sum using Two Pointers
bool twoSumSorted(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return true;
        else if (sum < target) left++;
        else right--;
    }
    return false;
}

// Sieve of Eratosthenes
vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    return is_prime;
}

// BFS (Breadth-First Search)
void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// DFS (Depth-First Search)
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfs(neighbor, adj, visited);
    }
}

// Dijkstra's Algorithm (Shortest Path in Weighted Graph)
vector<int> dijkstra(int src, int n, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first, node = pq.top().second;
        pq.pop();
        if (d > dist[node]) continue;
        for (auto& edge : adj[node]) {
            int next = edge.first, weight = edge.second;
            if (dist[node] + weight < dist[next]) {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }
    return dist;
}

// Floyd-Warshall Algorithm (All-Pairs Shortest Path)
vector<vector<int>> floydWarshall(vector<vector<int>>& graph, int n) {
    vector<vector<int>> dist = graph;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return dist;
}

// Find All Divisors of a Number
vector<int> findDivisors(int n) {
    vector<int> divisors;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) divisors.push_back(n / i);
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

// Matrix Multiplication
vector<vector<long long>> multiplyMatrix(vector<vector<long long>>& a, vector<vector<long long>>& b, int mod) {
    int n = a.size();
    vector<vector<long long>> res(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    return res;
}

// Dynamic Programming - Fibonacci (Bottom-Up)
long long fibonacci(int n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// String Reversal
string reverseString(string s) {
    reverse(s.begin(), s.end());
    return s;
}

// Convert String to Lowercase
string toLowerCase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// Convert String to Uppercase
string toUpperCase(string s) {
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

// Remove Duplicates in a Vector
vector<int> removeDuplicates(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    return nums;
}

// Big Number Operations
string addBigNumbers(string a, string b) {
    string res = "";
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res += (sum % 10) + '0';
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}
// Subtract two large numbers
string bigNumSubtract(string a, string b) {
    bool negative = false;
    if (a == b) return "0";

    if (a < b) {
        swap(a, b);
        negative = true;
    }

    string result = "";
    int carry = 0, diff;
    int n1 = a.size(), n2 = b.size();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for (int i = 0; i < n2; i++) {
        diff = (a[i] - '0') - (b[i] - '0') - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back(diff + '0');
    }

    for (int i = n2; i < n1; i++) {
        diff = (a[i] - '0') - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result.push_back(diff + '0');
    }

    while (result.size() > 1 && result.back() == '0')
        result.pop_back();

    reverse(result.begin(), result.end());
    return negative ? "-" + result : result;
}

// Multiply two big numbers
string bigNumMultiply(string a, string b) {
    int n = a.size(), m = b.size();
    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + result[i + j + 1];

            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string product = "";
    for (int num : result) {
        if (!(product.empty() && num == 0)) {
            product.push_back(num + '0');
        }
    }

    return product.empty() ? "0" : product;
}

// Division of big numbers
string bigNumDivide(string a, string b) {
    if (b == "0") return "undefined"; // Division by zero check

    string result = "";
    string temp = "0";

    for (char digit : a) {
        temp += digit;
        int count = 0;
        while (bigNumSubtract(temp, b)[0] != '-') {
            temp = bigNumSubtract(temp, b);
            count++;
        }
        result += (count + '0');
    }

    result.erase(0, result.find_first_not_of('0'));
    return result.empty() ? "0" : result;
}

// Function to get remainder of two large numbers
string bigNumModulo(string a, string b) {
    if (b == "0") return "undefined"; // Modulo by zero check

    string temp = "0";

    for (char digit : a) {
        temp += digit;
        while (bigNumSubtract(temp, b)[0] != '-') {
            temp = bigNumSubtract(temp, b);
        }
    }

    return temp;
}
//Backtrack
void backtrack(vector<int>& nums, vector<int>& subset, int index, vector<vector<int>>& result) {
    result.push_back(subset);
    for (int i = index; i < nums.size(); i++) {
        subset.push_back(nums[i]);
        backtrack(nums, subset, i + 1, result);
        subset.pop_back(); // Undo choice
    }
}

// Get all subsets of a set
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> subset;
    backtrack(nums, subset, 0, result);
    return result;
}

// 1. Arrays and Linked Lists
void arrayExample() {
    int arr[] = {1, 2, 3, 4, 5};
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

struct Node {
    int data;
    Node* next;
};

void linkedListExample() {
    Node* head = new Node();
    head->data = 10;
    head->next = nullptr;
    cout << "Linked List head data: " << head->data << endl;
}

// 2. Stack
void stackExample() {
    stack<int> stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << endl;
}

// 3. Prefix Sum and Difference Array
void prefixSumExample() {
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> prefixSum(arr.size(), 0);
    prefixSum[0] = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    for (int i = 0; i < arr.size(); ++i) {
        cout << prefixSum[i] << " ";
    }
    cout << endl;
}

// 4. Deque and Sliding Window Min-Max
void slidingWindowMinMax() {
    deque<int> dq;
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    for (int i = 0; i < arr.size(); ++i) {
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (dq.front() <= i - k) {
            dq.pop_front();
        }
        if (i >= k - 1) {
            cout << arr[dq.front()] << " ";
        }
    }
    cout << endl;
}

// 5. Binary Heap
class BinaryHeap {
    vector<int> heap;
    void heapify(int i) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;
        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        while (i > 0 && heap[i] < heap[(i - 1) / 2]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int top() {
        return heap[0];
    }

    void pop() {
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapify(0);
    }

    bool empty() {
        return heap.empty();
    }
};

// 6. Hash Table
void hashTableExample() {
    unordered_map<int, string> hashMap;
    hashMap[1] = "One";
    hashMap[2] = "Two";
    hashMap[3] = "Three";

    for (auto& kv : hashMap) {
        cout << kv.first << ": " << kv.second << endl;
    }
}

// 7. Sparse Table and RMQ Problem
class SparseTable {
    vector<vector<int>> st;
    vector<int> arr;
    int n, logn;

public:
    SparseTable(vector<int>& input) {
        arr = input;
        n = arr.size();
        logn = log2(n) + 1;
        st.resize(n, vector<int>(logn));
        build();
    }

    void build() {
        for (int i = 0; i < n; ++i) {
            st[i][0] = arr[i];
        }
        for (int j = 1; j < logn; ++j) {
            for (int i = 0; i + (1 << j) - 1 < n; ++i) {
                st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int j = log2(r - l + 1);
        return min(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

// 8. Persistent Data Structures (simplified)
class PersistentVector {
    vector<int> data;
    PersistentVector* prev;

public:
    PersistentVector() : prev(nullptr) {}

    PersistentVector(vector<int>& newData, PersistentVector* previous) : data(newData), prev(previous) {}

    void push_back(int value) {
        data.push_back(value);
    }

    int at(int index) {
        return data[index];
    }

    PersistentVector* getPrev() {
        return prev;
    }
};

// 9. Skip List
struct SkipListNode {
    int value;
    vector<SkipListNode*> forward;
    SkipListNode(int val, int level) : value(val), forward(level, nullptr) {}
};

class SkipList {
    SkipListNode* header;
    int maxLevel;
    float probability;

public:
    SkipList(int maxLvl, float prob) : maxLevel(maxLvl), probability(prob) {
        header = new SkipListNode(-1, maxLevel);
    }

    void insert(int value) {
        vector<SkipListNode*> update(maxLevel, nullptr);
        SkipListNode* current = header;
        for (int i = maxLevel - 1; i >= 0; --i) {
            while (current->forward[i] && current->forward[i]->value < value) {
                current = current->forward[i];
            }
            update[i] = current;
        }
        int level = randomLevel();
        SkipListNode* newNode = new SkipListNode(value, level);
        for (int i = 0; i < level; ++i) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }

    int randomLevel() {
        int level = 1;
        while (rand() % 2 < probability && level < maxLevel) {
            ++level;
        }
        return level;
    }
};

// 10. Binary Jumping with Memory
class BinaryJumping {
    vector<int> arr;

public:
    BinaryJumping(vector<int>& input) : arr(input) {}

    int binaryJump(int index) {
        int bestJump = arr[index];
        for (int jump = 2; index - jump >= 0; jump *= 2) {
            bestJump = max(bestJump, arr[index - jump]);
        }
        return bestJump;
    }
};
