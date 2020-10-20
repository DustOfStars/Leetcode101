/*
一群小孩站一排, 每人有个评分, 给他们发糖, 规则是如果一个小孩的评分比他旁边人高,那他糖果必须比旁边人多, 每人至少一个糖果
求: 最少需要多少糖果

输入: 评分[1,0,2]
输入: 最少糖果数 5

思路: 不需要排序, 直接只用两次遍历, 1.所有孩子分一个糖, 2.从左到右遍历一次, 若分数右>左, 糖果右<=左, 则右=左+1; 3.从右到左再来一次一样的
贪心策略的体现为: 再每次遍历中,只考虑并更新相邻的两个人, 最后从两边看过去都满足条件了
*/

int candy(vector<int>& ratings)
{
	int size = ratings.size();
	if (size<2)
	{
		return size;  //0个或者1个人, 只需要0或1糖果
	}
	
	vector<int> num(size, 1); //size行1列?
	
	for (int i=1; i<size; ++i)
	{
		if (ratings[i] > ratings[i-1])  num[i] = num[i-1]+1;
	}
	
	for (int i=size-1; i>0; --i)
	{
		if (ratings[i] < ratings[i-1])  num[i-1] = max(num[i-1], num[i]+1); 
	}
	
	return accumulate(num.begin(), num.end(), 0);  //求和
}
