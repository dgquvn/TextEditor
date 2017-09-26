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

#ifndef EDITOR_HPP_
#define EDITOR_HPP_

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>
#include "TextContent.hpp"

/**
 * This is the class to do manipulations on the file,
 * including viewing the file, adding a line, deleting a line,
 * and replacing a line.
 */
class Editor{
public:
	/**
	 * Constructor for get a reference to the TextContent
	 */
	Editor(TextContent& file);

	/**
	 * View the content of the file
	 */
	void display();

	/**
	 * provide the procedure for adding a line
	 */
	void addLine();

	/**
	 * provide the procedure for deleting a line
	 */
	void deleteLine();

	/**
	 * provide the procedure for replacing a line
	 */
	void replaceLine();

	/**
	 * writing content to the file
	 * @param file_loc file location for saving the file
	 */
	void writeToFile(const std::string& file_loc);

private:
	/**
	 * a reference to TextContent
	 */
	TextContent& text;
};



#endif /* EDITOR_HPP_ */
