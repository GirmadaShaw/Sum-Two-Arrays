/*
Given two array A[0….n-1] and B[0….m-1] of size n and m respectively, representing two numbers
such that every element of arrays represent a digit. For example, A[] = { 1, 2, 3} and
B[] = { 2, 1, 4 } represent 123 and 214 respectively. The task is to find the sum of both the number.
In above case, answer is 337.

Input : n = 3, m = 3
        a[] = { 1, 2, 3 }
        b[] = { 2, 1, 4 }
Output : 337
123 + 214 = 337
Input : n = 4, m = 3
        a[] = { 9, 5, 4, 9 }
        b[] = { 2, 1, 4 }
Output : 9763
*/

#include <iostream>
#include <vector>

void display(std ::vector<int> ans)
{
    std ::cout << "Required sum is: ";
    for (int i = 0; i < ans.size(); i++)
        std ::cout << ans[i] << " ";
}

void reverse(std ::vector<int> ans)
{
    int i = 0, j = ans.size() - 1;
    while (i < j)
    {
        std ::swap(ans[i++], ans[j--]);
    }
    display(ans);
}

void SumNum(int arr1[], int arr2[], int size1, int size2)
{
    int carry = 0, i = size1 - 1, j = size2 - 1, sum = 0;

    std ::vector<int> ans;

    while ((i > -1) && (j > -1))
    {
        sum = arr1[i--] + arr2[j--] + carry;
        carry = sum / 10;
        sum %= 10;
        ans.push_back(sum);
    }

    while (i >= 0)
    {
        sum = arr1[i--] + carry;
        carry = sum / 10;
        sum %= 10;
        ans.push_back(sum);
    }

    while (j >= 0)
    {
        sum = arr2[j--] + carry;
        carry = sum / 10;
        sum %= 10;
        ans.push_back(sum);
    }
    
    while ( carry > 0 )
    {
        sum = carry ; 
        carry /= 10 ;
        sum %= 10 ;
        ans.push_back(sum) ;
    }

    reverse(ans);
}

int main()
{
    // int arr1[] = {1, 2, 3};
    // int arr2[] = {5, 4};

    // int arr1[] = {2, 1, 4};
    // int arr2[] = {9, 5, 4, 9};

    int arr1[] = {9, 9, 9, 9};
    int arr2[] = {9, 9, 9, 9};


    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    SumNum(arr1, arr2, size1, size2);
}