/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpalusze <cpalusze@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 11:20:08 by cpalusze          #+#    #+#             */
/*   Updated: 2023/03/17 10:10:41 by cpalusze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

using std::string;

void replace(const string &s1, const string &s2, std::ifstream &inputFile, std::ofstream &outputFile) {
	string line;
	while (std::getline(inputFile, line)) {
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != string::npos) {
			line.erase(pos, s1.size());
			line.insert(pos, s2);
			pos += s2.size();
		}
		outputFile << line << std::endl;
	}
}

int main(int argc, char **argv) {
	string filename;

	if (argc != 4) {
		std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	if (static_cast<string>(argv[2]).size() == 0) {
		std::cerr << "s1 cannot be empty" << std::endl;
		return 1;
	}

	filename = argv[1];
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		std::perror("Input file");
		return 1;
	}

	std::ofstream outputFile(filename.append(".replace").c_str(), std::ios_base::out | std::ios_base::trunc);
	if (!outputFile.is_open()) {
		inputFile.close();
		std::perror("Output file");
		return 1;
	}
	replace(argv[2], argv[3], inputFile, outputFile);
	inputFile.close();
	outputFile.close();
	return 0;
}
