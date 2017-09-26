/**----------------------------------------------------------------------------
 Copyright (c) 2015-, UT-Battelle, LLC
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 * Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 * Neither the name of fern nor the names of its
 contributors may be used to endorse or promote products derived from
 this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 Author(s): Guoqiang Deng (dgquvn <at> gmail <dot> com)
 -----------------------------------------------------------------------------*/

#include "TextContent.hpp"

/**
 * Constructor for the class
 */
TextContent::TextContent(const std::string& file_loc){
	// open file
	std::ifstream file(file_loc);


	if (file.is_open()){

		// read line
		std::string line;

		// save text content
		while(std::getline(file, line)){
			content.push_back(line);
		}

		/* not working for lines
		std::copy(std::istream_iterator<std::string>(file),
				std::istream_iterator<std::string>(),
				std::back_inserter(content));
		*/

		// close file
		file.close();
	}
	else
		throw "cannot find file";
}

/**
 * Add a line to a specific location
 */
void TextContent::addLine(int index, const std::string& line){
	if (index >= content.size())
		content.push_back(line);
	else if (index >= 0)
		content.insert(content.begin()+index, line);
	else
		std::cout << "negative index\n";
}

/**
 * Delete a specific line from the file
 */
void TextContent::deleteLine(int index){
	if (index >= 0 && index < content.size())
		content.erase(content.begin()+index);
	else
		std::cout << "invalid index\n";
}

/**
 * Replace a line with another one
 */
void TextContent::replaceLine(int index, const std::string& line){
	if (index >= 0 && index < content.size())
		content[index] = line;
	else
		std::cout << "invalid index\n";
}

/**
 * get the text content
 */
const std::vector<std::string>& TextContent::getContent() const{
	return content;
}


