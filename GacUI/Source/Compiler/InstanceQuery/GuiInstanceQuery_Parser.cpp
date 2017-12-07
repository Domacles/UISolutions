﻿/***********************************************************************
Vczh Library++ 3.0
Developer: Zihan Chen(vczh)
Parser::GuiInstanceQuery_Parser.parser.txt

This file is generated by: Vczh Parser Generator
***********************************************************************/

#include "../../../Import/Vlpp.h"
#include "GuiInstanceQuery_Parser.h"

namespace vl
{
	namespace presentation
	{
/***********************************************************************
ParserText
***********************************************************************/

const wchar_t* const parserTextBuffer[] = {
  L"" L"\r\n"
, L"class Query" L"\r\n"
, L"{" L"\r\n"
, L"}" L"\r\n"
, L"" L"\r\n"
, L"enum NameOption" L"\r\n"
, L"{" L"\r\n"
, L"\tSpecified," L"\r\n"
, L"\tAny," L"\r\n"
, L"}" L"\r\n"
, L"" L"\r\n"
, L"enum ChildOption" L"\r\n"
, L"{" L"\r\n"
, L"\tDirect," L"\r\n"
, L"\tIndirect," L"\r\n"
, L"}" L"\r\n"
, L"" L"\r\n"
, L"class PrimaryQuery : Query" L"\r\n"
, L"{" L"\r\n"
, L"\tChildOption\t\tchildOption;" L"\r\n"
, L"\tNameOption\t\tattributeNameOption;" L"\r\n"
, L"\ttoken\t\t\tattributeName;" L"\r\n"
, L"\tNameOption\t\ttypeNameOption;" L"\r\n"
, L"\ttoken\t\t\ttypeName;" L"\r\n"
, L"\ttoken\t\t\treferenceName;" L"\r\n"
, L"}" L"\r\n"
, L"" L"\r\n"
, L"class CascadeQuery : Query" L"\r\n"
, L"{" L"\r\n"
, L"\tQuery\t\t\tparent;" L"\r\n"
, L"\tQuery\t\t\tchild;" L"\r\n"
, L"}" L"\r\n"
, L"" L"\r\n"
, L"enum BinaryOperator" L"\r\n"
, L"{" L"\r\n"
, L"\tExclusiveOr," L"\r\n"
, L"\tIntersect," L"\r\n"
, L"\tUnion," L"\r\n"
, L"\tSubstract," L"\r\n"
, L"}" L"\r\n"
, L"" L"\r\n"
, L"class SetQuery : Query" L"\r\n"
, L"{" L"\r\n"
, L"\tQuery\t\t\tfirst;" L"\r\n"
, L"\tQuery\t\t\tsecond;" L"\r\n"
, L"\tBinaryOperator\top;" L"\r\n"
, L"}" L"\r\n"
, L"" L"\r\n"
, L"token INDIRECT = \"////\";" L"\r\n"
, L"token DIRECT = \"//\";" L"\r\n"
, L"token NAME = \"[a-zA-Z_][a-zA-Z0-9]*\";" L"\r\n"
, L"token WILDCARD = \"/*\";" L"\r\n"
, L"token OPEN = \"/(\";" L"\r\n"
, L"token CLOSE = \"/)\";" L"\r\n"
, L"token XOR = \"/^\";" L"\r\n"
, L"token INTERSECT = \"/*\";" L"\r\n"
, L"token UNION = \"/+\";" L"\r\n"
, L"token SUBSTRACT = \"-\";" L"\r\n"
, L"token ATTRIBUTE = \"@\";" L"\r\n"
, L"token COLON = \":\";" L"\r\n"
, L"token DOT = \".\";" L"\r\n"
, L"" L"\r\n"
, L"discardtoken SPACE = \"/s+\";" L"\r\n"
, L"" L"\r\n"
, L"rule PrimaryQuery QPrimaryFragment" L"\r\n"
, L"\t=\t(" L"\r\n"
, L"\t\t\t(NAME : typeName with {typeNameOption=\"Specified\"})" L"\r\n"
, L"\t\t\t| (\"*\" with {typeNameOption=\"Any\"})" L"\r\n"
, L"\t\t)" L"\r\n"
, L"\t\t[\".\" NAME : referenceName] as PrimaryQuery" L"\r\n"
, L"\t;" L"\r\n"
, L"" L"\r\n"
, L"rule PrimaryQuery QPrimaryAttributed" L"\r\n"
, L"\t= !QPrimaryFragment with {attributeNameOption=\"Any\"}" L"\r\n"
, L"\t= \"@\" [NAME : attributeName] \":\" !QPrimaryFragment with {attributeNameOption=\"Specified\"}" L"\r\n"
, L"\t;" L"\r\n"
, L"" L"\r\n"
, L"rule PrimaryQuery QPrimary" L"\r\n"
, L"\t= (\"/\" with {childOption=\"Direct\"}) !QPrimaryAttributed" L"\r\n"
, L"\t= (\"//\" with {childOption=\"Indirect\"}) !QPrimaryAttributed" L"\r\n"
, L"\t= \"(\" !QueryRoot \")\"" L"\r\n"
, L"\t;" L"\r\n"
, L"" L"\r\n"
, L"rule Query Query0" L"\r\n"
, L"\t= !QPrimary" L"\r\n"
, L"\t= Query0 : parent QPrimary : child as CascadeQuery;" L"\r\n"
, L"" L"\r\n"
, L"rule Query Query1" L"\r\n"
, L"\t= !Query0" L"\r\n"
, L"\t= Query1 : first \"^\" Query0 : second as SetQuery with {op=\"ExclusiveOr\"}" L"\r\n"
, L"\t= Query1 : first \"*\" Query0 : second as SetQuery with {op=\"Intersect\"}" L"\r\n"
, L"\t;" L"\r\n"
, L"\t" L"\r\n"
, L"rule Query Query2" L"\r\n"
, L"\t= !Query1" L"\r\n"
, L"\t= Query2 : first \"+\" Query1 : second as SetQuery with {op=\"Union\"}" L"\r\n"
, L"\t= Query2 : first \"-\" Query1 : second as SetQuery with {op=\"Substract\"}" L"\r\n"
, L"\t;" L"\r\n"
, L"" L"\r\n"
, L"rule Query QueryRoot" L"\r\n"
, L"\t= !Query2" L"\r\n"
, L"\t;" L"\r\n"
};
const vint lengthTextBuffer[] = {
  2, 13, 3, 3, 2, 17, 3, 13, 7, 3, 2, 18, 3, 10, 12, 3, 2, 28, 3, 28, 35, 25, 30, 20, 25, 3, 2, 28, 3, 18, 17, 3
, 2, 21, 3, 15, 13, 9, 13, 3, 2, 24, 3, 17, 18, 21, 3, 2, 26, 22, 39, 24, 20, 21, 19, 25, 21, 24, 24, 20, 18, 2, 29, 2
, 36, 6, 56, 40, 5, 46, 4, 2, 38, 55, 92, 4, 2, 28, 58, 61, 23, 4, 2, 19, 14, 54, 2, 19, 12, 75, 73, 4, 3, 19, 12, 69
, 73, 4, 2, 22, 12, 4
};
const vint lengthTextBufferTotal = 1943;

		vl::WString GuiIqGetParserTextBuffer()
		{
			vl::collections::Array<wchar_t> textBuffer(lengthTextBufferTotal + 1);
			wchar_t* reading = &textBuffer[0];
			for(vint i = 0; i < sizeof(parserTextBuffer) / sizeof(*parserTextBuffer); i++)
			{
				memcpy(reading, parserTextBuffer[i], lengthTextBuffer[i] * sizeof(wchar_t));
				reading += lengthTextBuffer[i];
			}
			*reading = 0;
			return &textBuffer[0];
		}

/***********************************************************************
SerializedTable
***********************************************************************/

const vint parserBufferLength = 5817; // 27819 bytes before compressing
const vint parserBufferBlock = 1024;
const vint parserBufferRemain = 697;
const vint parserBufferRows = 6;
const char* const parserBuffer[] = {
"\x00\x00\x81\x81\x84\x02\x81\x80\x07\x82\x00\x87\x80\x83\x21\x33\x3B\x31\x30\x64\x65\x11\x35\x35\x32\x39\x3D\x7F\x18\x99\x98\x8A\x85\x84\x8C\x28\x39\x69\x6D\x21\x36\x83\x8D\x8B\x8A\x8D\x19\x85\x08\x80\x0A\x90\x81\x92\x8B\x28\x99\x88\x0B\x93\x98\x83\x29\x32\x74\x2F\xA7\x91\x9B\x03\x94\x8E\x81\x1C\x8C\x8E\x90\x82\x8C\x8A\x8B\x96\x05\xC8\xA3\x28\x39\x34\x34\x33\x98\x1B\xBE\x81\x82\xAF\x81\x8A\x9C\x03\x2B\xD8\x80\x90\x33\x95\x32\x36\x3A\x50\xFF\x7F\x86\x81\x87\x8D\x91\x91\x79\x3A\x8D\x0B\x9B\xB0\x81\x30\x3A\x74\x20\xA2\x35\x34\x3D\x32\x27\x30\x6D\x65\x21\xA3\xB9\x85\xB0\x90\x91\x24\xC6\xB9\x33\x0B\x94\xC2\xB6\xB8\x72\xF4\xB6\xB8\xB5\x37\x24\x38\x3A\x69\x6F\x2E\x3B\xB2\xA8\x82\xB2\xC0\x69\x82\xFD\x88\x8B\xC8\x03\xA5\xA6\x64\x0E\xD0\xD2\xC4\xC8\x86\x8F\xBF\x68\xEA\xAC\xA1\x82\x3D\x32\x33\x8A\x5E\xE3\x0B\xD9\xB5\xD5\x8E\xBF\xB3\x81\xA6\xB5\x85\x8B\xDC\x39\x3C\x38\xB3\xFA\x90\xBC\xB0\x07\xD0\xDD\xCC\x26\x8E\x2B\x8A\xE0\x86\xDC\xE1\xBB\x79\xA2\xD1\xD3\xC0\xAB\xDE\x81\xDD\x37\xB9\x82\xC8\xA2\x80\xA6\x33\x34\x72\x73\x20\xB5\xE4\x99\x81\xEC\x9D\x02\x2B\xA9\xE0\x8F\x30\x39\xB0\xEB\x01\xD8\xF8\x97\xA9\xA9\x83\x39\x32\x63\x12\xCF\xB0\xA1\x0B\x97\x17\x95\xFD\x6B\x42\x83\x4A\x61\x61\x53\x80\x81\x05\xB1\x47\x80\x42\x09\x8A\x8B\x82\x40\x0D\xA8\x40\x7C\x40\xBB\x49\x1E\x10\x11\x49\x12\x15\x13\x10\x54\x04\x48\x42\x87\x00\x2F\x02\x8B\x7F\x08\xB1\x4A\x55\x41\x27\x98\x8A\x84\x87\xEB\x45\x4D\x8A\x88\x01\x25\x88\x48\x88\x02\x60\x8E\x11\x10\x4D\x05\x15\x07\x4A\x3B\x80\x4B\x15\x18\x2D\x3A\x11\x11\x0B\x5A\x1F\x1D\x17\x8F\x41\x83\x9A\x14\x0C\x2D\x39\x0D\x16\x0A\x2D\x90\x84\x78\x42\xBB\x57\x19\x10\x13\x44\x03\x11\x12\x14\x44\x11\x91\x43\x8B\x2A\x03\x02\x8E\x46\x34\x83\x41\x43\x13\x50\x05\x1E\x12\x97\x00\x6F\x88\x09\x99\x00\x61\x5C\x75\x40\x48\x43\x1C\x13\x13\x53\x05\x1C\x98\x00\x2F\xA9\x03\x9D\x9C\x50\x62\x98\x42\xA0\x00\x18\x1F\x12\x14\x7B\xAF\x8E\x17\x89\x52\xB1\x49\x03\x4A\x8F\x80\x46\x84\x15\x45\x12\x19\x9C\x8B\xEA\x41\x4F\x0A\x0A\x07\x23\x99\x4B\x4A\x48\x55\x1E\x11\x12\x4F\x2B\x99\xA4\x40\x2F\x2B\x03\x84\x00\x61\x51\xA5\x42\xAB\x53\x15\x12\x13\x14\x54\x12\x11\x10\x87\x31\x88\x49\xAC\x00\x2D\x2E\xAD\xA0\x4A\xBE\x81\x4E\xA9\x10\x54\x35\xA9\x12\x10\x55\x14\xAB\xAE\x40\xBB\x80\x1A\x02\xA7\x18\x7F\x9C\x4B\x54\x4F\x37\x9E\x13\xB2\x01\x7B\xAA\x0D\x67\xBF\x9A\x44\xA2\x40\x84\x84\x1F\x10\x15\xD8\x80\x4B\xAE\x0B\xC4\x61\x55\xBB\xB4\x08\x48\x53\x14\x14\xB7\x85\x1F\xB5\x40\x84\xAF\x03\x1F\x0A\x6D\x45\x41\x58\x89\x05\x50\x0B\x4A\xBF\x2E\x57\x68\x5A\x11\x72\x21\x17\x19\x5E\x5F\x5A\x0B\x4A\xC2\x01\xE8\x66\x44\xC1\x06\xC8\xC4\x1E\x0B\x52\x2F\x1F\x18\x1D\x53\x34\x13\x48\x1D\x3D\x85\x4D\xC4\x10\x20\x24\x0C\x0D\x14\x02\xCF\xC5\xC3\xC1\x5E\x74\x1E\x0C\xC0\xFD\x81\x44\xCA\xC3\x79\x10\xC8\xCB\x57\x16\x2B\x45\xCD\xC3\xC7\x72\xC2\xC6\x0B\x19\xDB\xC4\x07\x4A\x3F\xC0\x40\xCB\xC8\x25\xF1\xC7\xCA\xC4\x2B\xFF\xBE\xC9\xD1\x3A\xE9\xC2\x07\x4A\x4F\xF8\xC8\x65\xD3\x5F\x6E\x01\x0D\x2A\x2B\x58\xD0\x40\xD1\x30\xD4\xDA\xCA\x0E\x20\x28\x01\xD8\x08\x37\xB9\x80\x08\xD8\xCE\x41\x70\x0B\x1D\x69\x34\x18\x18\x08\x7B\x20\x09\xD8\x74\x8D\x4F\x63\x74\x08\x3D\x20\x02\x0B\x14\xC0\x63\x19\x1B\x77\x65\x24\x12\x08\x08\x7D\x20\x09\x08\x08\x7C\x23\xD2\x0A\x0A\x83\xEC\xDE\xD8\xDC\x72\xFF\x61\x72\x74\x92\x78\xDA\xDD\x10\x6E\x39\x13\xE1\xE1\x87\xE9\x00\xCB\x16\x7A\xEE\x03\xE1\xD9\x45\x27\xD0\x09\x6B\xAF\x6D\x6E\x1A\x6C\x74\xE0\x0D\x14\x08\x0D\x60\x05\xD2\x4E\x2C\xC2\x4C\xCB\xCB\x39\xC7\xDE\xD0\xD4\x4B\xDD\xDA\xED\xD5\x32\x1A\xD5\x42\xF0\x5C\xF9\xE1\xC5\xCA\x3E\x20\xD2\xDA\xD8\xA4\xE6\xE3\xDC\x63\x6B\xED\xDF\xD9\xDC\xCF\xD1\x76\xDD\xE5\x79\xFB\xDD\xDF\xDF\x69\x01\xEB\xE6\xE1\x88\xCA\xEC\xE1\xF4\x8F\xD4\xF2\xE4\xDD\x94\xEE\x16\xE6\x08\x98\xDA\xE4\xE0\xF8\x9E\xE0\x00\xEA\x08\xA2\xE4\xD8\x8D\xE9\x60\xE8\xE0\x6F\xEA\x6A\xEF\xE1\xEF\xEC\x82\x35\x75\x40\x37\x7C\x69\xDF\x74\x09\x6A\x05\x28\x80\xEE\x53\x66\x80\x17\x33\x02\x78\x02\x24\x7B\x02\x83\x66\x81\xE4\x63\x6C\x79\xF7\x6E\x7B\xF9\x50\x7E\x71\xE9\x51\x77\x39\x8C\x29\x7F\xFA\x7C\x68\x3E\xEE\x5E\x7F\x7D\x87\x69\x72\xD8\x0B\x7D\x70\xE9\x50\x75\x7A\x75\x63\x36\xFA\x59\x7D\x7D\xEF\x5D\x72\x7E\xA1\x62\x04\xC8\x4D\x79\x7E\xD7\x3B\x7C\x75\xD0\x7E\x7F\x1C\x32\x70\x66",
"\xDA\x4A\x6A\x6A\x14\x87\x7B\x57\x18\x0B\x24\x26\x88\x8E\x64\x4A\x93\x61\xC5\x17\x65\x08\x37\x24\x0D\x63\x02\x3D\x62\xC8\x13\x80\x8B\x99\x6A\x60\x04\x40\x08\x82\x40\x0A\x85\x69\x20\x08\x31\x0D\x73\x35\x2C\x19\x41\x65\x20\x36\x9C\x89\x0F\x66\x91\x2C\x1A\x8A\x34\x0C\xAB\x43\x1B\x25\x77\x9B\x6B\x1B\xF1\x89\x30\x35\x96\x81\x04\x6F\x9E\x68\xC8\x1D\x80\x73\xB7\x32\x89\x8D\x93\x77\x7B\x0C\x97\x79\x73\xCD\x4D\x02\x01\xC5\x78\x30\x1F\xF3\x8E\x8E\xB0\x7A\x83\x70\xA0\x7C\x84\xEC\x67\x88\x91\xD6\x6F\x72\x04\x3A\x03\x70\x20\x85\x81\x8B\x41\xAE\x81\x6E\x86\x9D\x8D\x22\xB2\x83\x85\xED\x40\x72\x70\x84\x62\x80\x40\x04\x8E\x77\x28\xA2\x89\x20\x64\x95\x96\x17\xAE\x05\x06\x08\x81\x22\x82\xA4\x9E\x8A\x05\xCB\x76\x7E\xB3\x68\x6B\x83\x79\x24\x7E\x07\xB0\x82\x85\xEC\x64\x86\x6F\xAF\x96\x85\xF8\x2B\x83\x7C\x42\xA6\x78\x84\xD6\x6C\x94\x0D\x8D\x98\x84\xF0\x73\x7D\x7E\x9A\x9A\x7E\xEA\x40\x89\x98\x21\x84\x8F\x38\x3A\x21\x8C\xEF\x4F\x80\x8E\x4E\xB4\x8C\x61\x05\x30\x9F\x1E\xEE\x9A\x8C\x8A\x56\x64\x0E\x55\x84\x0F\x05\x2B\x2B\x9E\x80\x1B\x8D\x8C\xF4\x81\x72\x0F\x60\x8B\x55\xDD\x2F\x8F\x59\x08\x28\xA0\x00\x6F\x8E\x80\x5B\x2B\x26\xA1\x7A\x85\x6B\x30\xFA\x6F\x05\x16\xA5\x78\x04\x9F\x2E\x29\x33\xFA\x64\x08\xF0\x38\x3C\x0E\xD2\x83\x94\xCC\x13\x98\x90\x32\x00\x0F\x91\x91\x88\x2F\x44\xA2\x02\x44\x8B\x9E\x81\xA3\xA1\x2A\x93\xFA\x49\x06\x8A\x8F\xA3\x08\xA4\xDD\x82\xA7\x71\x24\xA4\x8F\x93\x90\x97\x8D\x16\x82\x04\x0A\x22\x9A\x27\x29\xB4\x0A\x6F\x29\x1A\x85\x41\xBD\x77\x38\x59\x80\x04\x96\xC7\x36\x9C\x15\xD6\x89\x5E\x81\x39\x5F\x9F\x30\x63\xA0\x10\x0C\x51\x21\x13\x7A\x20\x06\x4B\xAE\x26\x60\x30\x06\x6B\x28\x2B\x26\xAC\x7A\x83\xAF\x1F\xEF\x8E\xA7\x91\x6A\xA8\x6C\x5F\xA6\x74\x57\x2A\x77\xA9\x37\xA6\x70\xA6\xB0\x63\x88\x55\x44\x29\x9C\xAE\x80\x26\xAB\x63\xA1\xAF\x42\xE3\xAE\x81\x1D\x2B\x26\xB0\x69\xA6\x24\x0C\x16\x81\xAE\xB0\x73\xA9\x65\x20\x16\xAC\xD8\x78\xA1\x77\xBD\x96\x2A\x30\x5B\xB5\x3E\x58\x8A\xB2\xB1\xAF\xAE\x02\x06\x88\xA5\x21\x68\xEE\xAA\xB0\xC6\xA3\xAA\xAE\x5D\x3F\x28\xC8\x12\xB8\xA2\xA6\x0E\x29\xAF\x20\x16\xB1\x51\x26\x2E\xAE\x00\x00\xB2\xB1\xCC\x25\x21\x6E\x9E\xB6\xA9\x7C\x9C\x59\x20\x9D\x3B\x8A\x5A\xE0\x85\xB7\xDB\x96\x21\x06\x9D\xA2\x31\x0C\x56\x6E\x17\x95\x0D\xB9\xB1\xC7\xAB\xAF\x58\xED\xAA\x27\x18\x26\xB6\x24\x31\x06\x77\x77\x61\x37\xA8\x11\x1E\x0B\x70\x8D\xA0\x07\x7D\x79\x36\x8A\xD8\xA7\x3A\x30\xCA\x90\x71\x7B\x6B\x75\x08\x3C\x23\x0C\x0D\x75\x13\x0D\x1A\x76\x0D\x30\x39\x1B\x74\xBA\xCA\xB7\xBB\x71\xDA\xB0\x3C\xF1\x3A\x6B\x7C\xE1\xA3\xBE\x7E\x66\xB3\x3E\xF4\x96\x98\x04\xEB\xB9\x78\x4D\xF5\x21\x3D\x8F\xB7\xBD\xB8\x2E\x6A\xB9\x72\xD8\xBE\x04\x1A\x2A\x13\x25\x17\xD0\xB9\x1E\x56\xB0\xAE\xE5\xBC\xBC\xBB\x7A\x7F\xB9\x64\xA7\xB0\x6C\x01\xE5\xB9\x76\xE7\xA6\x26\x29\x97\xA9\xC0\xBD\x6D\xBF\xBD\xF1\xB3\xBD\x7D\x8E\x9F\xA7\xFC\x9D\xC0\xBB\x1F\xDE\xBC\x0B\xA3\xCA\xB0\xD3\x66\xC4\x0C\x04\xDA\x3A\x8A\xE9\xB1\x6F\x16\xE2\x03\xC1\x15\x23\xBC\x4E\xFD\x0D\xB3\xA2\x4A\xA2\x20\x0A\xAC\xA1\x0C\x15\x1B\x24\x2A\xD1\xA1\xAB\xCA\x74\xA2\x0E\xC4\xCD\xB4\xD0\x1B\xA2\x04\x1D\xAD\x37\x4D\xA1\xA3\x9F\x43\xB4\x88\xA5\x40\xB9\xC8\x4B\x95\xAB\xC5\x97\xAE\xB1\xA6\xDA\x9A\x6C\x4D\xE4\x06\xA7\x25\xE0\x7A\xA7\x92\x81\xA0\x19\x4D\xC0\x67\x27\xC1\x21\xCA\x45\x7F\xB3\x07\x2B\x23\xD1\x2B\xC7\x39\xA8\x43\xA0\x64\x20\x82\x36\xA8\xA4\xA2\x00\xC2\x9B\xA7\xBB\x84\xC7\xBF\xB3\x0C\xC5\x26\xD2\xA4\xB1\xBB\x8D\xFB\xB0\x6D\xED\xA2\x38\x64\xDE\xA0\xBC\x89\xE2\xB8\x3F\x01\xE8\xC5\xC0\x26\x3C\xCA\x91\xAF\xC0\xBE\xF9\xB4\xBF\x09\xF6\xA4\x70\x9A\xB6\xCC\xC6\x4E\xE0\x06\xD3\x74\x00\xD4\x80\xA3\xDF\xC7\x20\xFA\x22\xD5\x70\x13\xA7\x57\x49\xCE\xC0\xC2\x50\xD3\xB0\xD8\xB9\xB6\x40\x3B\xBA\xB8\xA9\xB8\x9E\x8A\xBF\xA0\x21\x70\x99\xDB\xC2\xAD\x87\xDA\x27\x32\x13\xD1\x1E\x32\x06\x6A\x5C\x2B\x26\xDB\x1A\xD2\x06\x74\xD8\xB8\xBE\x93\x22\xDB\xD3\xDB\xD9\xC5\x77\xAB\x02\xD4\x1C\xE5\xC5\xD4\x27\xC3\x89\x8A\x96\x20\xD9\xF5\x55\x0E\x0D\xD3\x37\xBF\xAC\xE6\xDA\xBF\x74\xDD\xD5\xBF\xDD\xAD\x05\xBB\xB6\xDD\xD7\x53\xC2\xCC\xDE\x07\xC6\xCB\x14\x75\x02\x0C\xF1\x05\x63\xCC\x84\x79\xB0\x42\x46\xBB\xDA\x6D\xDC\xDC\x06\xA4\x0B\x25\xC6\xE1\xDD\xDE\x19\x2A\xDA\x6F\xEC\xD5\xD7\x86\xBE\xC0\xDE\x20\xC6\xE1\x9D\xF5\xD9\x7B\xBD\xF9\xD2\xD7\x1A",
"\xFC\xD8\xDD\x1E\xFF\xDC\x88\xA2\x02\xE0\x91\xD9\xBF\xDD\xE4\xA6\xE6\xBC\xA8\xD6\x23\x36\xEA\xB9\xD8\xCE\x8C\xE2\xC3\xE1\x00\xE3\x3E\x37\x90\x20\xB9\x9B\xA6\x9E\xEC\x82\x20\x37\x80\xA6\xCC\xF5\x92\x04\x1D\x2B\x23\xEA\x43\xF9\xC8\xEA\x02\xB6\x90\x10\x5B\xC9\x93\x0C\xA0\x69\x95\x94\x9D\x7E\xDE\x21\x90\x04\x3C\xC9\x8E\x8B\x5C\xC0\xED\x27\xA1\x82\xA6\x67\xAE\x95\x7B\xB0\x9D\x0F\xB5\x92\xC5\x3D\x48\xDB\xC6\x81\x96\xC2\x20\xA6\xD5\xBD\xDF\x9B\xF7\xD0\xE0\x21\xDB\xC9\x80\xA5\xEE\xD6\x03\xE7\x90\xC1\x40\xEE\xC6\x7B\xAD\xD2\xC6\x58\xF4\xC4\xDA\x1C\xD6\xE7\xC7\xAC\x8B\xB4\x5E\xC4\xF7\xE4\x86\xEC\xC5\xE2\xC7\xC3\xD9\x06\xC5\xEB\xEE\xE6\xD6\xE3\x67\x9B\xE5\x20\xD2\xD4\xDF\xDC\x22\xF1\xE7\xDF\xDC\xB0\xD5\x90\xD5\xBC\xE4\x39\xE5\xF1\xAA\x89\xEB\xF3\x95\xD2\x37\xF1\xD8\xDD\xE2\xBA\xA0\xD5\xE7\xD7\xF8\xE6\xD4\x3B\xE7\xE1\x1E\x29\xEA\x6F\x85\xCD\xE1\x2E\x44\xEB\xC8\xE8\x96\x22\x06\x65\xC1\x24\xD9\xE6\xCE\xDA\x6F\xAB\x23\xDB\xDC\xE0\x89\x58\x00\x2E\x55\x51\xF7\x91\xDA\x00\x1D\x33\xFB\x17\x76\x68\x16\x81\x2D\x62\x6A\xC6\xAB\xDC\xCC\xEA\x9C\x42\x49\xE7\xEA\x55\xAB\x88\x68\x4C\xAD\xFD\xD8\xF5\x85\x07\xAA\xC5\x26\xFE\x29\xB6\x20\x4F\x95\x9A\x6F\xAD\xF8\x82\x93\x6A\x7A\x18\x9E\x43\x76\x5B\x66\x76\x5D\x42\x31\x69\x71\x50\xE8\x3D\x76\xC5\x7F\x76\x27\x46\x74\xEB\x4B\x50\x4F\x7E\x7E\x4C\x71\x10\x4E\x73\x52\x7A\x65\x61\xF6\x72\x10\xF8\x75\x66\xEE\x71\x54\xFE\x7D\x75\xC6\x4B\x49\x58\x7E\x49\xA0\x64\x76\x06\x86\x34\x51\x49\x80\x25\x8C\x76\x71\x6A\x3D\x25\x41\x4D\xC6\x6A\x59\xC8\x6C\x7C\xA2\x73\x03\xA4\x72\x10\xA6\x79\x7B\x30\x73\x79\xEC\x65\x79\xEE\x64\x6A\xB1\x78\x79\xB3\x77\x78\x46\x66\x7B\x6E\x08\x7B\x82\x18\x7A\xD8\x63\x79\x02\x70\x84\x04\x77\x79\xC1\x7F\x6B\xB4\x73\x42\x42\x78\x7C\x45\x7C\x67\xC7\x1E\x67\x00\x10\x68\x30\x35\x61\x85\x65\x10\x61\x89\x7F\x79\x08\x68\x44\x5C\x68\xF7\x40\x6A\x49\x58\x7D\x00\x0A\x7D\x68\x87\x31\x01\x25\x10\x71\x80\x7E\x52\x47\x4F\xF9\x4E\x7C\x00\x19\x5B\xC2\x56\x12\xE7\x70\x46\x47\x70\x00\xEC\x78\x16\xFB\x71\x38\x1C\x0B\x12\x85\x8C\x4E\x83\x85\x47\x46\x5D\x33\x72\x04\x07\xFD\x45\x10\x8F\x80\x32\x58\x5A\x74\x58\x74\x06\x3E\x0F\x87\x81\x8A\x7F\x7A\x6E\x44\x05\x1C\x89\x1E\x83\x7F\x3C\x3A\x31\x8D\x87\x33\x05\x14\x8A\x43\x3F\x89\x25\x5E\x03\x5A\x88\x19\x98\x81\x7F\x68\x1E\x6C\x8C\x84\x07\x55\x51\x10\xF9\x22\x89\x64\x8A\x8A\x75\x72\x81\x30\x38\x87\x00\x0B\x5B\x81\x61\x8B\xC4\x1C\x11\xA7\x82\x51\xCB\x79\x07\x30\x0E\x54\xB7\x34\x58\x8B\x82\x8A\x74\x0D\x7D\x9D\x16\x8B\x5F\x5E\x03\xC5\x80\x03\xC1\x81\x61\x8A\x51\x8A\x1B\x3C\x85\x00\x0A\x50\xA7\x8A\x56\xC5\x81\x03\xC8\x86\x8D\x94\x6B\x8C\x1B\x3E\x8C\x01\x10\x8D\xF9\x5F\x8D\xD5\x86\x77\xCB\x51\x8B\xDA\x8C\x8D\x20\x00\x79\xD2\x84\x83\xD8\x61\x8E\x76\x7C\x6D\xE4\x8D\x88\xE6\x82\x34\x21\x37\x7A\xF3\x83\x71\xE2\x8B\x6D\xEB\x85\x83\xDB\x68\x8D\x8D\x8F\x8E\xE7\x81\x8F\xB9\x7C\x86\x6E\x8C\x87\xF7\x46\x18\x05\x10\x91\x74\x80\x8B\xCC\x8C\x8B\xB9\x58\x8E\x0E\x97\x31\x3E\x0C\x90\x01\x96\x54\x0F\x0B\x12\x1F\x96\x77\x46\x56\x90\xB2\x8B\x1A\xFC\x86\x7E\xF7\x49\x34\x08\x10\x55\x0C\x46\x4B\x11\x81\x48\x0D\x44\x03\xBE\x40\x10\xC0\x4A\x4B\x48\x39\x65\x18\x43\x82\x30\x4C\x65\xCC\x4C\x80\x30\x80\x4D\x70\x72\x4D\x2A\x4F\x5F\x2E\x5F\x42\xC8\x41\x43\x77\x3B\x4D\xEE\x3C\x39\xDE\x49\x43\xC5\x48\x3F\xA7\x3E\x43\xE3\x42\x76\xFF\x35\x44\x98\x5D\x8A\x88\x8B\x74\xF0\x79\x95\x95\x8E\x40\x79\x45\x10\x5F\x94\x86\x89\x8B\x56\xC1\x48\x80\x07\x61\x80\x75\x1B\x80\x2F\x85\x43\x11\x78\x66\x13\x83\x7F\x20\x88\x49\x4F\x96\x3A\x68\x92\x76\xA0\x44\x54\x65\x90\x59\x67\x9A\x80\x2E\x89\x94\x0D\x81\x83\x41\x91\x71\x9D\x2B\x92\x47\x4A\x8B\xC6\x3E\x45\x03\x90\x40\x26\x1F\x20\xDD\x29\x11\x58\x96\x98\xF2\x75\x52\x89\x96\x95\x8B\x9B\x12\x21\x00\x2D\xFF\x0B\x8A\x68\x13\x99\xE8\x42\x18\x02\x23\x02\x98\x93\x8D\xD2\x28\x14\x3A\x12\x20\x25\x01\x9A\xF4\x8A\x5C\xA3\x91\x90\x02\x27\x02\xA8\x90\x90\xF7\x8B\x9A\x76\x72\x20\x29\x08\x99\x1C\x92\x92\xF7\x42\x9B\x04\x92\x20\x2B\x08\x99\x1F\x03\x2F\xAC\x2B\x2E\xFF\x02\x20\xEB\x2C\x98\xC6\x97\x9C\x10\x22\x9C\xB5\x5B\x27\xC8\x9B\x2E\xC5\x99\x8B\xD7\x11\x10\x30\x42\x20\xF6\x80\x99\x67\x72\x31\xFF\x02\x9C\x83\x95\x10\xC0\x98\x9C\xDE\x91\x27\xC2\x9B\x2E\xD2\x28\x9C\xCC\x97\x9C\x9C\x98\x19\xA5\x95\x98",
"\xB6\x3E\x8A\x07\x89\x32\x70\x23\x20\x16\x92\x9D\x47\x99\x3E\xB7\x90\x00\xCF\x46\x42\x64\x05\x9D\x30\x91\x45\xFF\x0B\x27\xFD\x94\x83\x02\x1C\x86\xD9\x9B\x12\xEB\x2B\x2A\x03\xA8\x10\xF5\x99\x9C\x95\x15\x10\x1E\x04\x20\xEB\x23\x8B\x00\x1D\xA0\x0C\x2B\x2E\xDB\x92\x10\x9C\x8A\xA0\x09\x5D\x44\x0E\xAB\x12\xEF\x91\x87\x18\xA9\x14\x00\x2B\xA1\x54\x21\x81\xCC\x2B\x12\x22\x00\x2A\xDF\x96\x1B\xA6\x17\x1B\xE8\x9E\x99\xEA\x93\x40\xEC\x9A\x82\x5E\x4F\x9E\x02\x21\x9F\xCD\x13\x9F\x8A\x45\x9F\xF7\x9F\x4A\xFA\x99\x97\x5F\x15\x5B\x27\xA9\xA2\x30\xA4\x98\xEC\x4E\x35\xDD\x92\xA4\x63\x4F\x92\x6F\x95\x52\x34\xA5\x18\x4E\xA7\x18\x2D\x89\x4D\xD3\x1D\x9D\x84\x2D\x3E\x8F\x98\x8A\x74\x4F\x9F\xB0\x9F\x2A\x22\xA5\x10\x05\xAD\xA5\x01\xA0\x29\x60\xA4\x16\x08\x12\xA1\xFA\x2F\xA0\x2B\x16\xA6\x1F\xA2\x10\x15\xA1\x10\x17\xA1\x10\x07\xA5\x10\xDA\x8F\xA6\xE0\x9C\xA1\x21\xA3\xA1\x28\xA8\x10\x1E\xA0\xA7\x5F\xAB\x7E\x04\xA6\x88\x79\xA8\xA4\xE7\x99\x1A\x2E\xA4\xA4\x2D\x35\xA4\x06\x4D\xA4\x08\x16\xA3\x00\x0D\x93\x32\x4A\xA3\x0E\x89\x9F\x85\x9B\x9F\x5E\x45\x5B\x87\x88\xA4\x3D\xA6\x93\x29\x37\xA4\x48\xA8\x74\x4A\xA8\x81\x95\x8A\xA8\x11\x9F\xA4\x00\x05\x97\x6A\x93\x1D\x90\xA0\x98\x81\x37\xA5\x4B\xA4\x47\x8C\x91\xA7\x10\x2E\x54\xEF\x91\x9E\x00\xA1\x10\x6D\xA7\x20\xEB\x22\xAA\xCB\x6B\x1C\xF2\x98\x4D\x48\x92\x19\xA9\xA0\x94\x81\x39\xA9\x87\x92\x31\xC1\x93\xA6\x00\x13\x9E\xC7\x95\x9E\xC6\x93\xA8\xB9\x16\x11\xD4\x93\xA9\x3E\xA4\x07\xBA\xAF\x7C\xBC\xA7\xA3\xBE\xA9\x3E\x54\xA1\x10\xED\x34\xAC\x2D\x9E\x45\x5A\xAA\x2F\x7B\x25\x5B\x02\xAE\x9C\xD0\x9C\xA7\x62\xA8\xA0\xC8\xA5\x1C\x69\xAB\xAE\x10\xA0\x00\x6A\xA8\xAE\x08\x17\xAB\x00\x04\xA7\xC7\xA9\xA1\x08\x16\xAF\xB0\xA6\x26\x7A\xAB\xAE\xD2\x2B\xA7\x75\xA3\xA2\x7E\xAA\x2B\x26\xA1\xA8\x42\xAE\xAC\xC8\x10\xAD\x2F\xA3\x4B\x31\xAE\x35\xD5\xA9\x87\xD7\xAD\xA8\x38\xA2\x43\xDB\xA0\x10\xDD\xA2\xAD\x9A\xAF\xA3\x05\xBD\xA9\xDE\xA7\x9D\x9B\xAD\xA9\x03\x2C\xAA\xA0\xAE\x7E\x0F\xB0\x00\x10\x92\x10\x10\x96\xAA\x7D\x92\x19\x15\xB0\x00\x56\xAF\xA9\x94\x8E\x7E\xE1\xA2\x10\xE4\xAB\xAE\x7D\xA7\xA6\xE9\xAC\xA5\x78\xAB\xA2\x65\xAE\xAE\xED\xAB\xB3\x05\x14\xAF\xFA\xAB\x2E\x73\xAB\xAE\x1D\xAE\xAF\x77\xA8\xB3\x02\xB9\x40\x7F\xA8\x10\x97\xAD\x1D\x20\xB8\xB0\xE9\x96\xA8\xEB\x98\xA8\x51\x45\xB2\x8C\xAE\xA8\x53\xAB\x12\x55\xA9\x39\x1D\xBD\x9E\x1A\xBE\xB4\x20\xBF\xB5\x32\xA2\x31\x9C\xAD\xA9\x22\xB1\xB3\xF3\x75\xB2\x27\xB1\x10\x29\xBC\x97\x52\xA0\xAC\x39\xBB\xA3\x70\x79\xB6\x91\x9E\xAA\x0F\x2B\xAF\x71\x22\xAB\x4D\xBA\xB4\x28\x2B\x12\xF4\xA4\x9C\x76\xA6\x9C\x59\xB3\xB1\x5B\xB3\x28\xDC\xAE\xB5\x18\xB5\xAC\x29\x30\xB4\x10\x25\x5B\x81\xB7\x9C\xE6\xA6\x9C\xEF\xA9\x2F\xE2\x41\x1B\xC1\x11\xAD\x86\xA4\xA9\xC6\xA0\xB2\x6B\xA2\xAF\xBC\x1E\xB9\xEB\xA3\xB3\xC2\x22\xB9\x49\xB2\x10\xE3\xA7\xBA\x29\xA6\xB7\x82\x8A\x67\x67\xB8\xA4\x9A\x9A\xB0\xAF\xA4\xAB\xED\x20\xB2\xCF\x9D\xAC\x0B\xAA\x98\xB2\xB7\xA8\xBC\xBC\xB9\x29\x34\xBA\x71\x29\xBA\xC6\x9B\x2E\x41\xA5\x10\x25\xB2\x20\x52\xB5\xA8\xBC\xB5\xB5\xD6\x90\xB6\x74\x00\xA4\x63\xBB\xB8\xDF\xA6\xB6\xA2\xB3\xB0\x4C\xBC\x95\x24\xB7\x9C\x6D\xB0\x10\x6F\xB1\xA5\xBF\xAE\x06\x2D\xBF\xB2\xD6\xB8\xA5\x6A\x40\xBC\xB6\x56\xBA\x62\xBF\x21\x51\xB9\xBB\x94\x9B\xBB\xCC\xBC\xBC\xBE\xB1\xB6\x05\x1F\xB4\x29\xA4\xB6\x46\xA5\xBD\xD7\xB9\xBF\xE4\xB1\x38\x6C\xB4\xAA\x2A\xB1\xB7\x6E\x01\xAC\xF8\x9C\xBA\x9A\x85\x89\xF8\xBE\xB7\x9F\xBD\x85\x07\xC0\xA7\xFE\x9B\x27\xDD\x72\xB8\x08\x16\x02\xA7\x2F\xB7\x11\xC0\xB2\xB1\xB9\x07\xAF\xB2\xA4\xD3\x86\xBE\xC4\x10\xC1\x05\x1F\xAE\xC2\xBF\xC1\x16\xC9\x8B\x6F\x47\xBB\x20\xA5\xBB\x00\x10\x53\x02\x23\x8D\x0B\xC0\xBA\x09\xCD\x8B\x2D\xCC\x2A\x0D\xC0\x92\xB5\xA1\xB0\x5E\xAB\x95\x08\xC5\xBA\xEA\xAE\xB8\x64\xAC\xA0\x3E\xBD\xB3\x3C\xC0\x10\x42\xBB\xAE\x45\xB4\xB0\x08\x18\x02\x13\xC4\xB3\x2B\x18\xC4\x9D\xA3\x8D\x19\xC9\xA2\xDF\x86\xBE\x4E\x55\x5B\x7A\xB0\x00\xEB\x25\x81\x36\xC1\xA6\x3B\xC9\xC3\x7D\x10\xC4\x5C\xC0\x00\xEF\xA1\xAF\x59\xC6\xAB\x1A\xA1\xC4\xDB\x85\xC6\x37\xC9\xAF\x49\xCD\x55\x68\xCA\xC1\xA9\x9A\x58\x26\xCA\xC4\x5B\xAF\x63\x2B\xCF\xC6\xC7\x55\xC5\xFF\x0D\x9D\xEF\xAD\x9D\x55\xC7\xB4\x66\xCF\xAF\xEB\xAB\x2A\x7F\x82\x20\x7B\x24\xAF\x12\xCD\xC4\x76\xC6\x8C\x71\xCC\xC6\x5B\xAF\x58\x5F\x15\xC7\x5B\xAF\x55\xC6\x98\xC7\xEB",
"\x2C\x8B\xCD\x9B\xBE\x3C\xB0\x00\xB2\x53\xB5\x14\xCD\xC9\x5F\x56\xBE\xE6\xB1\x92\x9D\xCF\xC2\x57\xCB\xAE\x09\xAE\xC2\x3D\xC2\x10\x62\xC7\xAF\x22\xCE\xC5\x2F\xC3\xC4\x66\xC5\xC4\x69\xC5\x10\x4C\xCC\x9D\x98\xCA\xA2\x9A\xCD\x10\x55\x13\x5B\xEE\xBC\xC8\x9E\xC3\x56\xB5\x55\xCB\x6E\xC1\xC9\x63\x5F\xC4\xDF\x91\xC5\x7B\x23\xC5\x36\xB8\xC3\x2F\xC7\xCA\x63\xCD\xC5\x3E\xC6\xC6\x61\xCB\xAE\xB0\xCF\xC5\xB2\xC5\xA2\x6A\xC8\xB8\x9D\xA3\x90\x9B\xCA\xBC\x72\xCF\xCB\x8A\x55\x5B\xF6\xA8\x9C\xD3\x8B\xC8\x7F\x54\x83\x74\xC5\xC3\xE7\xBC\x8E\x78\xCA\xC7\x5C\xB6\xB4\xAA\xBF\xCC\xEC\x22\x87\x81\xC4\xA2\x0B\x26\xCC\x03\x2C\xCD\xBA\xCC\x57\xDE\xCE\xCB\xDF\xCF\x55\x86\xC0\xB2\xE5\xC7\x9C\xC7\x6E\xC8\x1B\x8F\xCD\xFF\xC3\x56\xDE\x98\xC7\x7E\xC8\xA4\x7B\x22\x2D\xEF\xA4\xCE\x89\xC0\x03\x25\xBB\x8F\x9E\x1F\x66\xE9\x32\x58\x73\x65\x67\x17\xC8\xC7\x80\xCD\xA9\x0F\xD6\x92\x48\xA3\x8D\x15\xD4\x7D\x01\x10\x53\xE9\x37\x6C\x61\x6F\x51\x17\xC2\xCF\x99\x96\xCF\xDF\x92\x9E\x22\xD3\xCC\xE0\xC6\x11\x30\x05\xBD\x94\xCC\xCC\xF8\xB0\xCA\x7B\x23\x7E\x00\x1F\x9E\x55\xCB\x2E\xF0\x4D\xCC\x39\xBF\xC2\xC4\x1B\xCA\x55\xC3\xCD\x46\xC5\x10\x2A\x0B\xC6\xE7\xC8\x10\x4D\xD8\xC8\xC4\xC8\x5D\xF8\xC2\xD1\x53\xDC\x7C\xE6\xB4\x8A\x35\x2B\xCC\x08\x13\xD4\xA8\xC9\x7D\x45\xDF\xD5\xEC\xAE\xCA\x62\xDA\xD4\xB3\xCA\xCA\x4E\xDB\xCE\xD1\xC3\xD2\x89\xC1\x03\xE6\xCA\xD6\xDF\xC9\xCE\x5B\xA9\xD0\xE6\x6D\xCE\xA4\xA8\xBA\xD4\xCD\xC6\x62\xD7\xCD\x0B\x25\xC8\x4B\xC2\xD0\x6D\xDF\xD6\xBA\x98\x6B\x90\xC5\xD3\x1B\x63\xC9\xB4\xBD\x46\x31\xCC\xD3\x3C\x23\xB8\x5F\xC2\xD4\xA6\xC1\xD6\xF2\xC7\xD4\x3F\xCB\xD6\xD8\xCC\xD4\x69\xD5\x5B\x51\xDC\xD6\x57\xDB\x61\x55\xD4\xD0\x89\xC2\x03\x59\xDE\xD8\xA4\xCB\x30\x91\xDB\xC5\x46\xDF\xB3\x5F\xC6\xD6\x97\xD8\xD6\x08\x11\xC2\xAE\xDC\xD9\x86\xDE\xD6\xA0\xD3\xC7\x25\x75\xD8\x74\xD8\xD5\xC2\x9D\x9D\xDB\xBC\x27\x79\xD9\xCD\xD6\xCA\xD7\x07\x2E\xD7\x47\xC0\xD8\x9D\xD4\xDB\xC6\x93\xD8\x00\x78\xDB\xBE\xC5\x5D\x29\xA8\xC7\xCB\x90\xB2\xDD\x9F\xD1\xB0\xB4\xC2\x45\x32\x2D\xC5\xB2\xA4\x04\xCD\x4E\x95\x8F\xD6\x82\x53\x9D\x0B\xBF\x54\x0D\xB6\x40\x78\xC4\xAF\x9F\xDF\xDA\x06\xB1\x10\x00\xBE\x9D\x17\xC8\xDD\x20\xBB\xDD\x89\x86\xC6\xFF\x0C\x8B\x8F\x82\xA4\x32\xDD\xAF\x9D\xAD\xD2\x5F\xCF\x0F\x0D\xD4\xD3\x50\xB6\xBD\x42\xAD\xDE\x2B\x1C\x02\x20\xB5\x9F\x74\x82\x2D\x9B\xDE\xDF\xCD\xDB\x84\xD2\x22\xCC\x50\xCD\xD6\xD2\x27\xC8\xB2\xD9\xDB\xC6\x85\xD2\x9C\x17\xD2\x18\xDA\x48\x1A\xD5\x53\x62\x64\x07\x1D\xD2\x9C\xD4\xDA\xE0\xC9\xA0\xD3\xEC\xD6\xDD\x30\x32\x2D\x04\xED\xA9\x06\xEF\x86\x74\x08\xE0\xC6\xD6\xD8\x32\x0D\xE0\x2F\xE4\xE1\x31\x01\xE1\x33\xEB\xE0\x8A\x56\xE1\x05\x1D\x19\x28\xDA\x48\x2A\xDC\xD1\x26\xE7\x1C\x2E\xD2\xC8\x20\xBA\x9B\x49\xA9\xDF\x41\xE8\x19\x28\xE5\xE0\x39\xB7\xE0\x2B\x19\xE0\x0F\xED\xD9\x31\xEF\xD7\x52\xD3\xDB\x36\xE5\xE5\x14\xE7\xD3\x88\xD4\x20\xD5\xC2\xA4\xCC\xAC\x98\x82\x53\x6F\x79\x0C\xDC\x4F\xD4\x90\x31\x05\xB2\x89\x21\x10\xED\x15\x9F\x48\x6E\x79\xCF\xBD\xD6\x2E\xDC\xD7\xDF\x9F\xE5\x0F\x21\xE6\x3C\x73\xE6\xEA\xC4\x71\x67\xEB\xAC\x13\xCD\x1E\x16\xDC\x6A\x31\x6F\x6A\x72\x0F\x8D\x9E\xB9\xD3\x5D\xDB\xD8\xC2\x9B\x27\x1B\x09\xD6\x41\xDB\x12\x20\x07\xDA\x3A\xB7\xD6\x01\x19\xE2\x2E\x2A\xCE\x94\xE2\xE2\x6A\xD8\x6D\xE7\xDC\x98\x2B\xE9\x91\x60\x1B\xDB\x2B\x19\x01\x8C\xEB\x2E\x94\xD2\xCD\xAA\xDF\x20\xC4\xD8\xD9\x58\xE8\xE3\xCC\x72\xD8\x81\xA4\xD8\x79\xE1\x90\x32\x0B\xE5\x66\xCE\xD5\x38\xD9\xE8\x2B\x1B\xE8\xE8\xD6\xC6\xEB\x2F\xE8\x66\xCE\xCC\x56\xC3\xE0\x99\xD2\xEC\xAB\xE5\xE6\x9A\xE1\xC3\x9D\xE6\x11\x46\x56\xD7\x08\x12\xEA\xBB\xEF\xC5\xA5\xEB\xDA\xA7\xED\xD7\x80\xBF\xE4\x37\xE6\xEC\x4B\x8E\xEA\x28\xC0\x00\xB0\xE3\xD7\xAC\xEB\x6D\xCF\xDA\x9C\x2B\x1D\x01\xB6\xBD\xB7\x0F\x25\xB9\x01\x1F\xBF\x65\x02\x20\xF0\xDA\x67\x02\x28\xC7\xA2\xC2\x10\xF4\xB8\xE8\x04\x2D\xDF\x29\xA3\xDD\xC2\xDE\x9D\xDF\x87\xE5\x13\xEF\xED\x14\xD7\x9C\x16\xDD\xE3\x32\x4B\xE1\x74\x6D\xE1\x1F\xE4\x20\x21\xE7\xEF\xE9\xD0\x10\xE3\xC5\xDB\x56\xEB\x12\x12\xE8\xE9\x14\x7F\xEF\xC6\x91\xF0\x19\xE2\x43\x3F\xE6\xF0\x49\xE8\x16\x43\xE4\xE2\xE4\x9B\xF0\xF5\xA7\xED\x99\xEA\x9A\x10\xF2\xF2\x13\xF2\xA4\x78\xC1\xED\x5E\xE3\xC2\x4B\xB2\xE6\x64\xE3\xF2\xE6\x68\xE6\x7D\xE0\x07\xBA\x98\x84\xC5\x82\xDA\xC2\x9C\xDA\x29\xA4\xE7\x0B\x26\xE7\xC2\x7F",
"\xF2\x14\x72\x03\x32\xFF\xEC\x6B\xE3\xB7\x57\x8F\x70\x6F\xE2\xE5\x48\xA6\xE8\x05\x1E\xEB\x0B\xC8\xC7\x7B\x21\x86\x0F\x2B\x2E\x7F\x80\xDB\xB8\x4C\xE4\x5B\xC4\x87\x9B\xE5\xE7\x1B\xFD\xCB\xB4\xEA\x2F\xD1\xD0\xD2\x20\xF3\xEF\xDE\x9D\xEE\xDD\xD7\x9C\xDF\xD7\x94\x9A\xBD\xBB\xD3\xA5\xDE\xEF\xCD\xA9\xF7\xD3\xBF\xEF\xD0\xB3\x77\xBA\x46\x85\xE2\x9C\xF1\xE1\x10\x64\xFF\xF4\xC2\x96\xEF\xDF\x9F\x9E\xD2\x2B\xCA\x56\xD0\xE3\x32\xE5\xEC\x30\xF7\x5C\xFC\xE2\xF1\x01\x94\xF1\x8C\x96\xF1\x5E\x6A\xE1\xB9\x8B\xD1\x1A\xFB\xB4\x6F\x4E\xD1\xF1\xCE\x9D\x80\xF3\xED\xC7\xC1\xDA\x85\xFD\xEF\xD8\xE8\x5D\x89\xF1\xE5\x86\xDC\xF8\x0F\x2E\xF8\x1A\x5E\xE3\x34\x8B\xD2\x37\x5A\xDF\x78\xC4\xE4\x9D\xA8\xEF\x64\xDB\xF9\x52\xED\xF9\x8A\xFC\x8E\xA1\xF2\xFB\xA3\xFB\xD0\xC2\x90\xEC\x31\xCA\xFB\x04\x22\x20\xD9\xDD\xFB\xBE\xFC\x20\x61\xFE\xD0\x20\xF1\xFC\xDF\x96\xF6\xEE\x7E\xDD\xB9\x80\xDE\x54\xB3\xA4\xCD\xB5\xB6\xBF\xBA\x9D\x6F\xF8\xA4\x71\xF2\x10\xC8\xF5\xF6\x74\xFD\xBA\x06\xCB\xDF\xF4\xD2\xFC\x78\xC2\x20\x24\x02\xFC\xDF\x9C\xD0\x97\xF7\xC9\xEA\xB5\xF1\x26\xD9\xC2\x17\xF3\x1D\x04\xF0\xE4\x94\xF5\x34\x96\xF8\xDF\xD6\xF4\xDA\x0B\x26\xFA\x70\x63\x1D\x19\xFC\xD2\x5D\xF8\xE7\xAD\xFE\xF1\xF4\x74\x41\x02\x11\x88\x74\xFE\x33\x5D\xBD\x67\x7F\x7C\x73\xDB\x42\x08\x02\x88\xFB\x59\x72\x8E\x62\x08\x3C\x75\xFD\x52\x0D\xF7\x73\xF9\x21\x5C\x3B\x33\x7F\xF4\x62\xEC\x4A\x81\x80\x0C\x00\xFA\x77\x44\x6F\x80\xC0\x28\xC3\x4F\x7C\x8C\x79\xFA\x70\x7E\x05\x91\x7E\x1D\x78\xC0\x69\x51\xEB\x7C\x01\xA6\x7B\xE2\x6F\x77\xC2\x4A\x40\x0E\x71\x02\x8B\x20\x66\x7C\xFD\x62\x52\xB0\x7C\x96\x6E\x80\xDB\x75\xF2\x06\x7F\xC4\x60\x81\xD2\x32\x04\xA7\x7D\x81\x71\xF9\x1C\x70\xFF\x71\x7F\x30\x18\x03\x82\x09\xF5\x68\x9C\x39\x82\x40\x13\x81\x1E\x87\xB8\x77\x7D\x28\x83\xFA\x40\x82\xF7\x22\x82\xF9\x7A\x32\x3B\x7F\xD5\x7D\xFF\x29\x81\xFE\x4B\x79\x1B\x80\x20\x10\x83\xC1\x74\xE3\x53\x80\x19\x9E\x77\x30\x87\xF7\x56\x76\x1A\x8F\xF5\x10\x12\xDF\x78\x7C\x20\x78\xCA\x4D\x81\x6F\x73\xE5\x45\x6E\x0F\x81\x48\x35\x75\x07\x9E\x7D\xC3\x75\xE1\x00\x7B\xFA\x77\x68\x23\x86\xFD\x45\x83\x82\x77\x04\xA7\x81\xE5\x60\x71\x08\x86\x38\x59\x7C\xA8\x6B\x03\x84\x49\x1D\x9A\x81\x77\x84\x07\x95\x61\x48\x84\x90\x24\x7F\xFD\x7F\x83\x02\x7A\xFF\x65\x81\x0A\x81\x9D\x6C\x26\x17\x87\x72\x48\x56\x09\x81\x08\x39\x84\x05\x94\x73\x23\x8F\x82\x8D\x85\xBA\x26\x82\x87\x79\xE5\x69\x82\x00\x84\x76\x6C\x81\x6F\x7D\x7B\x44\x8C\x98\x46\x73\xA4\x78\x7A\x91\x76\xC9\x4C\x84\x4A\x88\x6D\x34\x7E\xE8\x65\x83\x7A\x85\xF6\x55\x84\x2B\x81\x01\x81\x87\x04\x83\x84\x26\x85\x13\x91\x7E\x25\x8A\xDE\x45\x70\xC8\x77\x74\x29\x51\xD9\x79\x02\xA3\x2E\xE2\x3C\x84\x83\x74\x72\x7B\x82\xCF\x6B\x84\xE3\x44\xD2\x7E\x83\x85\x6C\x7F\xC6\x86\x0D\x1B\x82\x0F\x7D\x05\xAC\x64\x84\x0E\x7D\x48\x53\x11\x85\x08\x68\x8F\x9D\x52\x84\x35\x8B\x83\xD9\x82\xD6\x7E\x85\x39\x8F\xF9\x08\x7D\x30\x9F\x85\x68\x81\x16\x81\x08",
};

		void GuiIqGetParserBuffer(vl::stream::MemoryStream& stream)
		{
			vl::stream::MemoryStream compressedStream;
			for (vint i = 0; i < parserBufferRows; i++)
			{
				vint size = i == parserBufferRows - 1 ? parserBufferRemain : parserBufferBlock;
				compressedStream.Write((void*)parserBuffer[i], size);
			}
			compressedStream.SeekFromBegin(0);
			vl::stream::LzwDecoder decoder;
			vl::stream::DecoderStream decoderStream(compressedStream, decoder);
			vl::collections::Array<vl::vuint8_t> buffer(65536);
			while (true)
			{
				vl::vint size = decoderStream.Read(&buffer[0], 65536);
				if (size == 0) break;
				stream.Write(&buffer[0], size);
			}
			stream.SeekFromBegin(0);
		}
/***********************************************************************
Unescaping Function Foward Declarations
***********************************************************************/

/***********************************************************************
Parsing Tree Conversion Driver Implementation
***********************************************************************/

		class GuiIqTreeConverter : public vl::parsing::ParsingTreeConverter
		{
		public:
			using vl::parsing::ParsingTreeConverter::SetMember;

			bool SetMember(GuiIqNameOption& member, vl::Ptr<vl::parsing::ParsingTreeNode> node, const TokenList& tokens)
			{
				vl::Ptr<vl::parsing::ParsingTreeToken> token=node.Cast<vl::parsing::ParsingTreeToken>();
				if(token)
				{
					if(token->GetValue()==L"Specified") { member=GuiIqNameOption::Specified; return true; }
					else if(token->GetValue()==L"Any") { member=GuiIqNameOption::Any; return true; }
					else { member=GuiIqNameOption::Specified; return false; }
				}
				member=GuiIqNameOption::Specified;
				return false;
			}

			bool SetMember(GuiIqChildOption& member, vl::Ptr<vl::parsing::ParsingTreeNode> node, const TokenList& tokens)
			{
				vl::Ptr<vl::parsing::ParsingTreeToken> token=node.Cast<vl::parsing::ParsingTreeToken>();
				if(token)
				{
					if(token->GetValue()==L"Direct") { member=GuiIqChildOption::Direct; return true; }
					else if(token->GetValue()==L"Indirect") { member=GuiIqChildOption::Indirect; return true; }
					else { member=GuiIqChildOption::Direct; return false; }
				}
				member=GuiIqChildOption::Direct;
				return false;
			}

			bool SetMember(GuiIqBinaryOperator& member, vl::Ptr<vl::parsing::ParsingTreeNode> node, const TokenList& tokens)
			{
				vl::Ptr<vl::parsing::ParsingTreeToken> token=node.Cast<vl::parsing::ParsingTreeToken>();
				if(token)
				{
					if(token->GetValue()==L"ExclusiveOr") { member=GuiIqBinaryOperator::ExclusiveOr; return true; }
					else if(token->GetValue()==L"Intersect") { member=GuiIqBinaryOperator::Intersect; return true; }
					else if(token->GetValue()==L"Union") { member=GuiIqBinaryOperator::Union; return true; }
					else if(token->GetValue()==L"Substract") { member=GuiIqBinaryOperator::Substract; return true; }
					else { member=GuiIqBinaryOperator::ExclusiveOr; return false; }
				}
				member=GuiIqBinaryOperator::ExclusiveOr;
				return false;
			}

			void Fill(vl::Ptr<GuiIqQuery> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
			{
			}

			void Fill(vl::Ptr<GuiIqPrimaryQuery> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
			{
				SetMember(tree->childOption, obj->GetMember(L"childOption"), tokens);
				SetMember(tree->attributeNameOption, obj->GetMember(L"attributeNameOption"), tokens);
				SetMember(tree->attributeName, obj->GetMember(L"attributeName"), tokens);
				SetMember(tree->typeNameOption, obj->GetMember(L"typeNameOption"), tokens);
				SetMember(tree->typeName, obj->GetMember(L"typeName"), tokens);
				SetMember(tree->referenceName, obj->GetMember(L"referenceName"), tokens);
			}

			void Fill(vl::Ptr<GuiIqCascadeQuery> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
			{
				SetMember(tree->parent, obj->GetMember(L"parent"), tokens);
				SetMember(tree->child, obj->GetMember(L"child"), tokens);
			}

			void Fill(vl::Ptr<GuiIqSetQuery> tree, vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)
			{
				SetMember(tree->first, obj->GetMember(L"first"), tokens);
				SetMember(tree->second, obj->GetMember(L"second"), tokens);
				SetMember(tree->op, obj->GetMember(L"op"), tokens);
			}

			vl::Ptr<vl::parsing::ParsingTreeCustomBase> ConvertClass(vl::Ptr<vl::parsing::ParsingTreeObject> obj, const TokenList& tokens)override
			{
				if(obj->GetType()==L"PrimaryQuery")
				{
					vl::Ptr<GuiIqPrimaryQuery> tree = new GuiIqPrimaryQuery;
					vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
					Fill(tree, obj, tokens);
					Fill(tree.Cast<GuiIqQuery>(), obj, tokens);
					return tree;
				}
				else if(obj->GetType()==L"CascadeQuery")
				{
					vl::Ptr<GuiIqCascadeQuery> tree = new GuiIqCascadeQuery;
					vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
					Fill(tree, obj, tokens);
					Fill(tree.Cast<GuiIqQuery>(), obj, tokens);
					return tree;
				}
				else if(obj->GetType()==L"SetQuery")
				{
					vl::Ptr<GuiIqSetQuery> tree = new GuiIqSetQuery;
					vl::collections::CopyFrom(tree->creatorRules, obj->GetCreatorRules());
					Fill(tree, obj, tokens);
					Fill(tree.Cast<GuiIqQuery>(), obj, tokens);
					return tree;
				}
				else 
					return 0;
			}
		};

		vl::Ptr<vl::parsing::ParsingTreeCustomBase> GuiIqConvertParsingTreeNode(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
		{
			GuiIqTreeConverter converter;
			vl::Ptr<vl::parsing::ParsingTreeCustomBase> tree;
			converter.SetMember(tree, node, tokens);
			return tree;
		}

/***********************************************************************
Parsing Tree Conversion Implementation
***********************************************************************/

		vl::Ptr<GuiIqPrimaryQuery> GuiIqPrimaryQuery::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
		{
			return GuiIqConvertParsingTreeNode(node, tokens).Cast<GuiIqPrimaryQuery>();
		}

		vl::Ptr<GuiIqCascadeQuery> GuiIqCascadeQuery::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
		{
			return GuiIqConvertParsingTreeNode(node, tokens).Cast<GuiIqCascadeQuery>();
		}

		vl::Ptr<GuiIqSetQuery> GuiIqSetQuery::Convert(vl::Ptr<vl::parsing::ParsingTreeNode> node, const vl::collections::List<vl::regex::RegexToken>& tokens)
		{
			return GuiIqConvertParsingTreeNode(node, tokens).Cast<GuiIqSetQuery>();
		}

/***********************************************************************
Parser Function
***********************************************************************/

		vl::Ptr<vl::parsing::ParsingTreeNode> GuiIqParseAsParsingTreeNode(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::collections::List<vl::Ptr<vl::parsing::ParsingError>>& errors, vl::vint codeIndex)
		{
			vl::parsing::tabling::ParsingState state(input, table, codeIndex);
			state.Reset(L"QueryRoot");
			vl::Ptr<vl::parsing::tabling::ParsingGeneralParser> parser=vl::parsing::tabling::CreateStrictParser(table);
			vl::Ptr<vl::parsing::ParsingTreeNode> node=parser->Parse(state, errors);
			return node;
		}

		vl::Ptr<vl::parsing::ParsingTreeNode> GuiIqParseAsParsingTreeNode(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::vint codeIndex)
		{
			vl::collections::List<vl::Ptr<vl::parsing::ParsingError>> errors;
			return GuiIqParseAsParsingTreeNode(input, table, errors, codeIndex);
		}

		vl::Ptr<GuiIqQuery> GuiIqParse(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::collections::List<vl::Ptr<vl::parsing::ParsingError>>& errors, vl::vint codeIndex)
		{
			vl::parsing::tabling::ParsingState state(input, table, codeIndex);
			state.Reset(L"QueryRoot");
			vl::Ptr<vl::parsing::tabling::ParsingGeneralParser> parser=vl::parsing::tabling::CreateStrictParser(table);
			vl::Ptr<vl::parsing::ParsingTreeNode> node=parser->Parse(state, errors);
			if(node && errors.Count()==0)
			{
				return GuiIqConvertParsingTreeNode(node, state.GetTokens()).Cast<GuiIqQuery>();
			}
			return 0;
		}

		vl::Ptr<GuiIqQuery> GuiIqParse(const vl::WString& input, vl::Ptr<vl::parsing::tabling::ParsingTable> table, vl::vint codeIndex)
		{
			vl::collections::List<vl::Ptr<vl::parsing::ParsingError>> errors;
			return GuiIqParse(input, table, errors, codeIndex);
		}

/***********************************************************************
Table Generation
***********************************************************************/

		vl::Ptr<vl::parsing::tabling::ParsingTable> GuiIqLoadTable()
		{
			vl::stream::MemoryStream stream;
			GuiIqGetParserBuffer(stream);
			vl::Ptr<vl::parsing::tabling::ParsingTable> table=new vl::parsing::tabling::ParsingTable(stream);
			table->Initialize();
			return table;
		}

	}
}