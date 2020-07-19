#include "partitioner.h"
#include "common.h"
#include <stdlib.h>

int main(int argc, char *argv[]){
	if(argc < 2){
		printf("Need benchmark folder name, or \n");
		printf("ex ) %s aes \n", argv[0]);
		exit(0);
	}

	clock_t start,end;
	start = clock();		
	std::cout<<"****************************************\n";
	std::cout<<"*              DEF TO HGR              *\n";
	std::cout<<"****************************************\n";

	std::string input_name = argv[1];
	std::string deffile_name = input_name+"/"+input_name+".def";

	STR_LIST name_arr;
	name_arr = split(deffile_name, ".");
	std::string pure_name = name_arr[0];
	std::string hgr_name = pure_name + ".hgr";
	std::string fix_name = pure_name + ".fix";

	EDGE_GRAPH graph;
	STR_PAIR_LIST node_list;
	PIN pin_list;
	VERILOG_LIST v;

	//convert def to hgr format
	def_to_hgr(deffile_name,graph,node_list,pin_list);	
	
	
	end = clock();
	double result = (double)(end - start);
	
	printf("%.3f sec\n", result/CLOCKS_PER_SEC);
}

