/*
一群小孩分饼干, 小孩有饥饿度, 饼干有size, 每人最多一个饼干, 饼干大于饥饿度才能吃饱
问: 最多有多少个小孩能吃饱?

输入: [1,2], [1,2,3]
输出: 2

思路: 饥饿度最小的最容易吃饱, 先满足他, 给他一个大于等于他的最小饼干;  然后再去满足倒数第二...一直到条件:没有满足条件的饼干存在了

具体: 需要获得大小关系, 对小孩和饼干分别排序, 然后从最小的出发, 计算能有几个满足的二元组
*/

int findContentChildren(vector<int>& children, vector<int>& cookies)
{
  sort(children.begin(), children.end());
  sort(cookies.begin(), cookies.end());
  
  int child = 0, cookie = 0;
  while(child < children.size() && cookie < cookies.size())
  {
    if (children[child] <= cookies[cookie]) ++child;
    ++cookie;
  }
}
