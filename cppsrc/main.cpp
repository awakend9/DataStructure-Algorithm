#include "Algorithm.cpp"
#include "DataStructure.cpp"

using namespace std;

int main()
{	
	int i = 0;	
	float* test_mat = new float[Length];	
	for (i = 0; i < Length; i++)
	{
		test_mat[i] = rand();
		if (i == 98) {
			test_mat[i] = 520;
		}
	}//先生成测试数列，Length个浮点，其中第99个为520，方便测试
	std::cout << SequentialSearch(test_mat, Length, 520) << endl;//查找我的第99个520
	QuickSort(test_mat, 0, Length - 1);
	for (i = 0; i < Length; i++)
	{
		std::cout << test_mat[i] << " , ";
	}
	std::cout << endl;
	cout << examination_sort(test_mat, Length) << endl;
	delete[] test_mat;
	std::system("pause");
	return 0;
}