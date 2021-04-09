#include <iostream>

template <class CTy>
CTy fn_Partition(CTy* cp_Arr, int i_LowI, int i_HighI){
	CTy c_Pivot = cp_Arr[i_HighI]; // COMP: pivot
	int i_I = (i_LowI - 1);

	for (int i_J = i_LowI; i_J < i_HighI; i_J++){
		// COM: if current element is larger than or
		//     equal to pivot
		if (cp_Arr[i_J] >= c_Pivot){
			i_I++; // COMP: increment index of larger element
			CTy o_Tmp   =   cp_Arr[i_I];
			cp_Arr[i_I]    =   cp_Arr[i_J];
			cp_Arr[i_J]    =   o_Tmp;
		}
	}
	CTy o_Tmp         =   cp_Arr[i_HighI];
    cp_Arr[i_HighI]    =   cp_Arr[i_I + 1];
    cp_Arr[i_I + 1]      =   o_Tmp;
	return (i_I + 1);
}

template <class CTy>
void fn_QuickSortLomuto(CTy* cp_Arr, int i_LowI, int i_HighI){
	if (i_LowI < i_HighI){
		int i_PI = fn_Partition<CTy>(cp_Arr, i_LowI, i_HighI);

		fn_QuickSortLomuto(cp_Arr, i_LowI, i_PI - 1);
		fn_QuickSortLomuto(cp_Arr, i_PI + 1, i_HighI);
	}
}

int main(){
	int i_Arr[] = {10, 7, 8, 9, 1, 5};
	int i_Num = sizeof(i_Arr)/sizeof(int);

	fn_QuickSortLomuto<int>(i_Arr, 0, i_Num-1);
	std::cout<< "Sorted Results\n";

	for (int i_Ct=0; i_Ct < i_Num; i_Ct++)
		std::cout<< i_Arr[i_Ct]<< " ";
	std::cout<< "\n";
	return 0;
}
