//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};


// } Driver Code Ends
//User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        Node *start=head;
        Node *end=head;
        
        while(end->next!=NULL){
            end=end->next;
        }
        
        vector<pair<int,int>> ans;
        while(start!=end && start->prev!=end){
            int sum=start->data + end->data;
            if(sum<target){
                start=start->next;
            }
            else if(sum>target){
                end=end->prev;
            }
            else if(target==sum){
                 pair<int,int> temp=make_pair(start->data,end->data);
                 ans.push_back(temp);
                 start=start->next;
                 end=end->prev;
            }
        }
        // if(start->data==end->data){
        //     pair<int,int> temp=make_pair(start->data,end->data);
        //     ans.push_back(temp);
        // }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
