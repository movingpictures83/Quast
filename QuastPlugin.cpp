#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "QuastPlugin.h"

void QuastPlugin::input(std::string file) {
 inputfile = file;
}

void QuastPlugin::run() {
   
}

void QuastPlugin::output(std::string file) {
 // spades.py -o 02_Quast -1 $1 -2 $2 --careful
 // assembly-stats -t ./All_assemblies/*.fasta > ./All_assemblies/00_Metrics_all_assemblies.txt
	std::string command = "quast.py "+inputfile+"/*.fasta -o "+file+"; cp "+file+"/report.txt "+file+"/..";
 std::cout << command << std::endl;

 system(command.c_str());

}

PluginProxy<QuastPlugin> QuastPluginProxy = PluginProxy<QuastPlugin>("Quast", PluginManager::getInstance());
