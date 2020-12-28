#include<vector>
#include<math.h>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<stack>
#include<iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    };


 template <typename T>
void printVV_(vector<vector<T>> vv){
    int m = vv.size();
    int  n = vv[0].size();
    for (int i = 0; i < m; i++)
    {
       for (int j = 0; j < n; j++)
       {
           std::cout<< vv[i][j] <<" " ;
       }
       cout<< endl;
       
    }
    
}
class  Solution
{

public:

     Solution(/* args */ );
    ~ Solution();
    // 43 字符串相除
     string multiply(string num1, string num2) {
         int one = 0;
         int two = 0;
         int length = num1.length();
         for (size_t i = 0; i < length ; i++)
         {
             one = one + (num1[length - 1 - i ] - '0') * pow(10,i);
         }
         
        
    }
     ListNode* reverseKGroup(ListNode* head, int k) {
        
    }
    // 36 有效的数独 判断数独是否有效
    bool judgeRow(vector<vector<char>>& board,int row,int cel,char value){
        for (size_t i = 0; i < 9 ; i++)
        {
            if(i != cel &&board[row][i] != '.' && board[row][i] == value  )
                return false;
        }
        return true;
        
    }
    // 列
    bool judgeCel(vector<vector<char>>& board,int row,int cel,char value){
        for (size_t i = 0; i < 9 ; i++)
        {
            if(i != row && board[i][cel] != '.' &&  board[i][cel] == value)
                return false;
        }
        return true;
        
    }
    // 判断正方形 
    bool judgeRet(vector<vector<char>>& board,int row_,int cel_,int ret,char value){
        int row = ret / 3 * 3 ;
        int cel = ret % 3 * 3;
        for (size_t i = row ; i < row + 3 ; i++)
        {
            for (size_t j = cel; j < cel + 3; j++)
            {
                if(i == row_ && j == cel_)
                    break;
                if(board[i][j] != '.' &&board[i][j] == value)
                   {
                    //    std::cout<<std::endl<<"erroro " << row_<<cel_<<i << j << ret <<std::endl;
                       return false;
                   }
            }
            
        }
        return true;
        
    }
    bool isValidSudoku(vector<vector<char>>& board) {
     int ret = 0;
        for (size_t i = 0; i < 9; i++)
        {
           for (size_t j = 0; j < 9; j++)
           {
            //    std::cout << i << j;
            //    std::cout << " row ";
               if (!judgeRow(board,i,j,board[i][j]))
               {
                   return false;
               }
            //    std::cout << " cel ";
               if (!judgeCel(board,i,j,board[i][j]))
               {
                   return false;
               }
            //    std::cout << " ret ";
                ret =  i / 3 * 3 + j / 3 ;
               if (!judgeRet(board,i,j,ret,board[i][j]))
               {
                   return false;
               }
               
           }
           
        }
        return true;
        
    }
    // 29 两数相除 不用乘除法和mod
    int divide(int dividend, int divisor) {
       if(divisor == -1){
            if(dividend>INT_MIN) return -dividend;// 只要不是最小的那个整数，都是直接返回相反数就好啦
            return INT_MAX;// 是最小的那个，那就返回最大的整数啦
        }
        if(abs(dividend) < abs(divisor))
            return 0;
        int  n = 0;
        int divisors = divisor;
        if(divisor > 0 && dividend > 0){
        if(divisor == dividend)
            return 1;
        else
        {
            n = 0;
            while (divisors < dividend)
            {
                divisors += divisor;
                n++;
            }
            
        }
        
        }
        else if (divisor < 0 && dividend > 0)
        {
            n = 0;
            while ( abs(divisors) <= dividend)
            {
                divisors += divisor;
                n--;
            }
            
        }
        else if (divisor > 0 && dividend < 0)
        {
            
            n = 0;
            while ( divisors <= abs(dividend))
            {
                divisors += divisor;
                n--;
            }
        }
        
        else
        {
            n = 0;
            while ( divisors >= dividend)
            {
                divisors += divisor;
                n++;
            }
        }
        
        
        return n;
        
    }


    // 24 
    // 65.5 time
    // 100  memory
    // 搞清楚了letcode头节点都是第一个节点 head = first；
     ListNode* swapPairs(ListNode* head) {
             if(head == NULL || head ->next== NULL)
        {
            return head;
        }
        ListNode* p = head;
        ListNode* q = p->next;
        ListNode* pro = p;

        while (p != NULL && p->next != NULL)
        {
            q = p->next;
            
           p->next = q->next;
           
           if(pro == head){
                q->next = pro;
                head = q;
           }else
           {
               pro->next = q;
               q->next = p;
           }
           pro = p;
           
           p = p->next; 
           
         
        }
    
    return head;
        
        
    }

    // 44 通配符匹配
    
    // 35
    vector<vector<char>> cboard;
    int n = 3;
    int N = n * n;
    int rows [9][10] ={{0}};
    int colums [9][10] = {{0}};
    int boxes [9][10] = {{0}};
    bool suduSloved = false;
    bool couldPlaceNumber(int d,int row,int col){
        int idx = (row / 3) * 3 + (col / 3);
        return rows[row][d] + colums[col][d] + boxes[idx][d] == 0;
    }
    void  placeNumber(int d,int row,int col){
        int  idx = (row / 3) * 3  + (col / 3);
        colums[col][d] ++;
        rows[row][d] ++;
        boxes[idx][d] ++;
        cboard[row][col]  = (char)( d + '0');
    }
    void placeNextNumber(int row,int col){
        if(row == 8 && col == 8){
            suduSloved = true;
        }
        else
        {
            // 下一行 第一个元素
        if(col == 8)
        {
            backtrack(row+1,0);
        }
       else
            {
            backtrack(row,col+1);
            }
        
        }

    }
    void removeNumber(int d,int row,int col){
        int  idx = (row / 3) * 3 + (col / 3);
        colums[col][d] --;
        rows[row][d] --;
        boxes[idx][d] --;
        cboard[row][col]  = '.';
    }
    void backtrack(int row,int col){
        if(cboard[row][col] == '.') {
            for (int i = 1; i < 10; i++)
            {
                if(i==8 && col ==6){
                    i = 8;

                }
                if(couldPlaceNumber(i,row,col)){
                        placeNumber(i,row,col);
                        placeNextNumber(row,col);
                         if(!suduSloved){
                        removeNumber(i,row,col);
                    }
                }
                
            }
            
           
        }
        else
        {
            placeNextNumber(row,col);
        }
        
    }


     void solveSudoku(vector<vector<char>>& board) {
        cboard = board;
        
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                placeNumber((int)(board[i][j] - '0'),i,j);
            }
            
        }
       
        
        backtrack(0,0);
        cout<<endl;
        board = cboard;
        
        
    }
    // 28
    int strStr(string haystack, string needle){
        int m = haystack.size();
        int n = needle.size();
        if (m == 0 && n == 0)
        {
            return 0;
        }
        
        if (m == 0 )
        {
            return -1;
        }
        
        
        if(n == 0)
        {
            return 0;
        }
        int index = 0;
        for (int i = 0; i < m; i++)
        {
            if(haystack[i] == needle[index])
            {
                index++;
            }
            else
            {
                i = i - index + 1;
                index = 0;
                
            }
            if(index == n )
            {
                return i - index + 1;
            }
        }
        
        
        return -1;
    }
    // 84
     int largestRectangleArea(vector<int>& heights) {
         int s = 0;
         int n = heights.size();
         vector<int> left(n),right(n);
         stack<int> momo_stack;
        //  找到当前位置 i 能够拓展到的最左边位置
         for (int i = 0; i < n; i++)
         {
             while(momo_stack.empty() && momo_stack.top() >= heights[i]){
                 momo_stack.pop();
             }
             left[i] = (momo_stack.empty()?-1:momo_stack.top());
             momo_stack.push(i);

         }
         momo_stack = stack<int>();
         for (int i = n -1; i > 0; i--)
         {
             while(momo_stack.empty() && momo_stack.top() >= heights[i]){
                 momo_stack.pop();
             }
             left[i] = (momo_stack.empty()?n:momo_stack.top());
             momo_stack.push(i);

         }
         for (int i = 0; i < n; i++)
         {
             s = max(s,(right[i] - left[i] -1)* heights[i]);
         }
         return s;
         
         


     }
    // 84
    int largestRectangleArea_(vector<int>& heights) {
        int s = 0,max = 0;
        int left = 0;
        int right = 0;
        for (int i = 0; i < heights.size(); i++)
        {
            for (int j = i + 1; j < heights.size() && heights[i] < heights[j] ; j++)
            {
                right++;
            }
            for (int j = i - 1; j >= 0 && heights[i] < heights[j] ; j--)
            {
                left++;
            }
            s = (right + left + 1) * heights[i];
            if(s > max)
            {
                max = s;
            }
            right = left = 0;
        }
        
        
        return max;
    }
    // 81
     bool search(vector<int>& nums, int target) {
        if(nums[0] == target){
            return true;
        }
        for (int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == target)
                return true;
            else if ( nums[i] < nums[i - 1])
            {
                break;
            }
           
        }
        
        
    }
    int removeDuplicates(vector<int>& nums) {
        int freq = 1;
        for (int  i = 1; i < nums.size(); i++)
        { 
      
            if(nums[i] == nums[i - 1]){
                cout<< nums[i] << nums[i -1] << endl;
                freq++;
            }
            else
            {
                freq = 1;
            }
            if(freq > 2){
                cout<< " use" << endl;
                cout<< *(nums.begin() + i - 1) << endl;
                nums.erase(nums.begin() + i - 1);
                freq = 2;
                i--;
            }
        }
        return nums.size();
        
    }


    bool searchMatrix(vector<vector<int>>& matrix, int target) 
     {
        // 二分查找 有几个注意点，第一个，左右指针，用大于小于等于
        // 用两次 二分查找 分别寻找行和列
        int m = matrix.size();
        if (m == 0)
        {
            return false;
        }
        int n = matrix[0].size();
        if (n == 0)
        {
            return false;
        }
        cout<<m<<endl;
        for (int i = 0; i < m; i++)
        {
            int hig = n - 1;
            int low = 0;
            int middle = (hig + low) / 2;
            if (matrix[i][hig] < target)
            {
                continue;
            }
            while(low <= hig){
                cout<<"matrix[i][middle]"<<matrix[i][middle]<<endl;
                 if (matrix[i][hig] < target)
                {
                    break;
                }
                if (matrix[i][middle] == target)
                {
                    cout<<"matrix[i][middle]"<<matrix[i][middle]<<endl;
                    return true;
                }
                else if(matrix[i][middle] < target)
                {
                    low = middle + 1;
                }
                else if (matrix[i][middle] > target)
                {
                    hig = middle - 1;
                }
                middle = (hig + low) / 2;            
            } 
            if (matrix[i][middle] == target)
            {
               return true;
            }
             
           
            
        }     
    return false;
    }
};
 Solution:: Solution(/* args */)
{

}

 Solution::~ Solution()
{

}
template<typename T>
// void printVV(vector<T> vint ){
//     for (vector<T>::iterator it = vint.begin(); it < vint.end(); it++){
//         printV(it);
//         std::cout<< std::endl;
  
//     }
//     cout<<endl;
  
    
// }
// template<typename T>
// void printV(vector<T>& vint ){
//     for (vector<T>::iterator it = vint.begin(); it < vint.end(); it++){
//         cout<<*it<<" ";
  
//     }
//     cout<<endl;
  
    
// }


void printString(string out){
    cout<<out<<endl;

}
class a{
  
  public:
    a(){

    };
   virtual ~a(){

   };
   void get_add_double(double*  dou_2){
        dou_2 = &(this->dou_1);
   }
   void set(double val){
       this->dou_1 = val;
   }
   void show_double(){
       cout<<" show "<<dou_1<<endl;
   }
    private: 
    
    double dou_1;
    int b;
};

void printList(ListNode* head){
    ListNode* pList = head;
    while (pList->next!=NULL)
    {
        cout<<pList->val<<" ";
       pList = pList->next;
    }
     cout<<pList->val;
     cout<<endl;
    
}
//    vector<vector<char>> board;
//     board.push_back({'8','3','.','.','7','.','.','.','.'});
//     board.push_back({'6','.','.','1','9','5','.','.','.'});
//     board.push_back({'.','9','8','.','.','.','.','6','.'});
//     board.push_back({'8','.','.','.','6','.','.','.','3'});
//     board.push_back({'4','.','.','8','.','3','.','.','1'});
//     board.push_back({'7','.','.','.','2','.','.','.','6'});
//     board.push_back({'.','6','.','.','.','.','2','8','.'});
//     board.push_back({'.','.','.','4','1','9','.','.','5'});
//     board.push_back({'.','.','.','.','8','.','.','7','9'});
int main(int argc,char** argv){

    
    
    // ListNode  *p1 = new ListNode(1);
    // ListNode  *p2 = new ListNode(2);
    // ListNode  *p3 =  new ListNode(3);
    // ListNode  *p4 = new ListNode(4);
    // ListNode  *head = p1;
    // p1->next = p2;
    // p2->next = p3;
    // p3->next = p4;
    // p4->next = NULL;
    // ListNode * result ;
    // Solution s;
    // p1->val = 1;
    // printList(head);
    // result = s.swapPairs(head);
    // printList(head);
 
    
        // Solution s;
        // if(s.isValidSudoku(board)){
        //     std::cout<< "true" << std::endl;
        // }else
        // {
        //     std::cout<< "false" << std::endl;
        // }
    string num1 = "1000000000000000000000000000000000000000000000000000";
    int_fast64_t one = 0;
    int length = num1.length();
    for (size_t i = 0; i < length ; i++)
         {
             one = one + (num1[length - 1 - i ] - '0') * pow(10,i);
         }
    std::cout << one << std::endl;
   

    return 0;
}
