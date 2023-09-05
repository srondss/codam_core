/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 09:32:42 by ysrondy           #+#    #+#             */
/*   Updated: 2023/09/03 09:32:43 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string replace(std::string fileContent, std::string toFind, std::string toReplace)
{
	for (unsigned long i = 0; i < fileContent.length(); i++)
	{
		if (fileContent.substr(i, toFind.length()) == toFind)
		{
			std::cout << "Found " << toFind << " at index " << i << std::endl;
			std::cout << "Erasing " << toFind << " and inserting " << toReplace << std::endl;
			fileContent.erase(i, toFind.length());
			fileContent.insert(i, toReplace);
			i += toReplace.length();
		}
		if (fileContent[i] == '\0')
			break;
	}
	return (fileContent);
}

std::string	readFile(std::string fileName)
{
	std::ifstream fileToReadFrom(fileName);
	if (!(fileToReadFrom.is_open()))
	{
		std::cerr << fileName << " was unable to be opened.\n";
		exit(EXIT_FAILURE);
	}
	std::string fileContent;
	std::string line;
	while (getline(fileToReadFrom, line))
	{
		fileContent += line + "\n";
	}
	std::cout << "Text from File:\n----------------------------------\n" << fileContent;
	fileToReadFrom.close();
	return (fileContent);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Incorrect number of arguments.\nUsage: ./main [INPUT_FILE] "
		"[STRING_TO_FIND] [STRING_TO_REPLACE]" << std::endl;
		return (EXIT_FAILURE);
	}
	// Read from file into fileContent string.
	std::string fileContent = readFile(argv[1]);
	if (fileContent.empty())
	{
		std::cerr << "File is empty." << std::endl;
		return (EXIT_FAILURE);
	}

	// Find and replace argv[2] with argv[3] in fileContent.
	std::cout << "\nReplacing " << argv[2] << " with " << argv[3] << "\n----------------------------------" << std::endl;
	fileContent = replace(fileContent, argv[2], argv[3]);
	std::cout << "\nNew Text:\n----------------------------------\n" << fileContent;

	// Open new file to write to.
	std::string newFileName = argv[1];
	newFileName += ".replace";
	std::ofstream fileToWriteTo(newFileName);
	if (!fileToWriteTo.is_open())
	{
		std::cerr << "Error opening file for writing." << std::endl;
		return (EXIT_FAILURE);
	}

	// Write to file.
	fileToWriteTo << fileContent;
	fileToWriteTo.close();
	std::cout << "\nWriting to new file:\n----------------------------------\n";
    std::cout << newFileName << " created and written to successfully." << std::endl;

	return (0);
}


