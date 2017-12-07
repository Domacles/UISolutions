﻿#include "DarkSkin.h"

namespace vl
{
	namespace presentation
	{
		namespace user_resource
		{
			using namespace collections;
			using namespace stream;
			using namespace controls;

			class DarkSkinResourceReader
			{
			public:
				static const vint parserBufferLength = 1281; // 2935 bytes before compressing
				static const vint parserBufferBlock = 1024;
				static const vint parserBufferRemain = 257;
				static const vint parserBufferRows = 2;
				static const char* parserBuffer[2];

				static void ReadToStream(vl::stream::MemoryStream& stream)
				{
					DecompressStream(parserBuffer, true, parserBufferRows, parserBufferBlock, parserBufferRemain, stream);
				}
			};

			const char* DarkSkinResourceReader::parserBuffer[] = {
				"\x77\x0B\x00\x00\xF9\x04\x00\x00\x05\x00\x01\x82\x80\x03\x03\x82\x81\x82\x01\xC4\x2F\x23\x38\x06\x81\x81\x86\x01\xC9\x2E\x33\x34\x39\x32\x37\x31\x65\x0D\x0E\x80\x0A\x89\x8B\x89\x8A\x17\xE5\x13\x34\x39\x3C\x35\x32\x02\x1B\xA8\x81\x94\x25\x30\x3C\x3B\x07\x1B\xB0\x81\x83\x2C\x31\x33\x39\x39\x4E\x61\x2D\x25\x32\x2D\x33\x31\x37\x72\x64\x1B\x84\x8B\x88\x8A\x82\xA3\x44\x61\x32\x2B\x33\x2B\x35\x34\x37\x01\x43\x9B\x90\x03\xAA\x82\x20\x9B\x65\x6C\x0F\xA5\x3A\x83\x31\x3B\x9D\x6E\x74\x3E\x5B\x83\xB1\x80\x1F\xAE\x3E\x3C\x03\x2F\x31\xB5\x31\xB1\x17\x69\xA3\xA5\x85\x33\x39\xB8\x92\x93\x20\x6E\x3A\x85\x3D\x1A\x13\x10\x22\x65\x66\x21\x35\x3C\x34\x39\x17\x27\x76\x65\x32\x32\x39\x34\x31\x32\x11\x69\xBF\xAC\x20\xAE\x1B\x12\x23\xCB\x98\xBC\x2F\x12\xC4\xCA\xCE\xB8\x93\x76\xF3\xB9\xBB\xBD\xBB\x13\x29\xAC\x3E\xF4\x29\x2C\xB7\xC1\xC7\xC5\xC6\x8F\x91\xEF\x33\xC2\x3D\xC8\xCD\xCC\x9B\xB3\xDD\xC2\x3B\x34\xCD\xDB\x11\x30\x30\x37\x01\x23\x23\x22\xCC\xDE\xBE\xE9\xAF\x1F\xC5\x32\xE4\xE7\xBA\x9A\xE8\x83\xAC\x0B\x8C\xE9\x81\x23\x61\x63\x07\x2E\xBB\xB6\x36\x33\x34\x67\x43\x91\xAE\x88\x86\x81\xF3\x21\x70\x70\x00\x84\xFB\x8D\x8E\x82\xF7\xE8\xF0\x2B\xAD\x30\x3A\x38\xBB\x39\x65\x64\x14\x1B\x8B\xF9\x86\xA4\xA6\x4E\x6E\x1D\x4F\x1C\x6F\x35\x12\x1C\x46\x2E\x23\x19\x79\x79\x03\x6A\x46\x42\x83\x39\x7B\x46\x53\x40\x48\x7F\x7D\x53\x53\x0C\x82\x4E\x7B\x40\xEE\x4E\x10\x51\x1B\x61\x2C\x12\x47\x18\x6C\x35\x1E\x60\x55\x0E\x68\x80\x02\x0B\x2E\x2F\x0C\x8A\x8B\x2D\x98\x73\x19\x15\x49\x2E\x08\x19\x86\x01\x51\x0B\x46\x8E\x01\x7D\x46\x1A\x49\x63\x2A\x6C\x5B\x88\x25\x8E\x69\x0F\x46\x47\x81\x4F\x8B\x92\x2D\xBE\x80\x92\x90\x6E\x2F\x04\x15\x1E\x70\x1C\x54\x5F\x18\x8C\x70\x14\x1C\x50\x73\x2F\x07\x11\x1D\x69\x0E\x99\x6B\x6A\x6E\x10\x15\x8B\x19\x4F\x76\x88\x8C\x00\xD6\x46\x4D\x9B\x14\x05\x87\x85\x1A\x11\xB3\x4E\x62\x1E\x01\x1B\x78\x91\x40\x9C\x06\x98\x43\x53\x02\x1B\x40\xA1\x40\x14\xF6\x7F\x44\x7D\x1A\x26\x64\x13\x7B\x83\x31\x4D\xA3\x4D\x4D\x37\x51\x8C\x4E\x4F\x40\x64\x11\x0F\x46\x24\x18\xA2\x40\x19\xFF\x73\x11\x82\x0E\x3A\x02\x1F\x18\x1D\x5B\xAD\x13\x14\x96\xB3\x6C\x12\x11\x1D\xA4\xAC\x5C\x48\x7D\x35\x74\x15\x18\x06\x1B\x74\xA1\x40\xA7\x4B\x5E\xAF\x50\xA8\xAB\xAD\xAE\x1B\xAB\x70\x31\xA5\x1A\x06\x1B\x44\xB7\xAD\xA7\x9F\xBA\x03\x10\x1A\x3E\x6B\x12\xA8\x1E\xC0\x82\xB5\x0B\x46\xD3\x87\xB9\xAD\xB2\xCB\x8D\xB9\x12\xAC\x6D\x17\x53\x1B\x1A\x67\x32\x15\x82\x1B\x64\x11\xB1\x1A\xAC\xC6\x86\x49\xB8\xAE\x6B\x3A\xAE\x18\xA8\xF3\x62\x1F\x1B\xB3\xE6\xB2\xAF\x07\x46\xF7\x96\xBD\xB8\xB6\x75\x14\x4F\x19\x1B\xDD\x74\x12\xB8\x1B\xF5\xA5\x12\x4E\x41\x07\xEC\xBE\xB8\xA8\x54\x0C\xBB\x4C\x07\x1B\x50\xCA\xBF\xC2\x3A\x09\x52\xAC\x14\x69\x1F\xBA\x61\xC1\xF9\x86\x4D\xC6\xC2\xC9\x9D\x5F\x56\x5B\x74\x0C\x11\x1A\x18\x59\x45\xC1\x0B\x46\x2B\xD3\xC1\xCB\x42\x23\xE1\x5C\x4A\x4B\xF4\xA5\x10\xAF\xB9\x65\x20\x0B\x46\xCE\x2E\xFB\xA5\xC4\xCC\x60\x74\x16\x15\x1A\x65\x37\x1B\xC6\xCD\xC1\xB8\xC9\xA6\x43\x4B\xC0\x00\xCA\xCF\x45\x38\x10\x1E\x45\x64\x0F\x57\x18\x60\x3F\x72\x17\xB8\x50\x05\xE9\xB3\x43\xBA\xC8\xBE\xC7\x12\xB8\x75\x30\x15\xCF\xCD\xF6\xB8\xBB\xA5\xD8\xEF\xBA\x08\x13\xA9\x03\xEC\x18\x10\xD5\x26\x45\xC9\x07\x46\x77\xFD\xCD\xDB\xDB\xA8\xAC\x14\xC0\xD2\xC2\x9E\xD2\x40\xD8\xD7\xBE\xC8\x10\x15\x5A\xDA\xC2\x1D\xC1\x3C\xC6\x4D\xE3\xD3\x6D\xDB\xB6\xCE\xB7\xE0\xA4\xD4\xB9\xC1\x17\x1B\x49\xE6\xDE\xA0\xA6\xC8\xCB\xDF\x68\xCF\x6B\x46\x08\x6B\xC5\xED\xD8\x13\x81\x74\x10\xDD\xAA\xBD\x9B\x9F\xAC\xE0\x38\xE6\x0B\x46\xEC\x9C\xFA\x0C\x11\x1A\x14\x43\xD5\xD3\x5A\x25\xAD\x1E\x18\x12\x65\x21\x16\x9D\xD7\xC5\xA5\xEB\xBE\xCF\xB7\xF9\xE4\xD3\x1D\x1C\xEA\xD5\xED\x13\x6E\x75\x17\x56\x1C\xAD\xEE\xA0\xEE\xAC\x8D\xC3\x4F\xE0\xDB\xA0\x90\xFE\x19\x1D\x92\xDD\xBC\xAA\xEB\x05\xDE\x0B\x46\xF9\xCF\xD1\xF3\x15\xB0\x69\x24\xA7\xD1\xE8\xA4\xCE\x41\xFE\xD3\xDC\xFA\x0D\x10\x61\xAA\x5A\x5E\x19\x19\x33\xF4\x17\xD9\xD2\xB2\x5D\x03\x46\x02\x85\x76\x42\x6F\x09\x5C\xF7\x33\x79\xC1\x04\x86\x20\x06\x90\x70\x54\x52\x02\x7B\x6A\x55\x7F\x75\xD0\x63\x03\x23\x17\x95\x76\x14\x60\x38\x0C\xD5\x7D\x6A\x55\xE3\x76\x79\xE8\x12\x66\x20\x12\x8F\x82\x07\xAB\x7E\x6E\xEE\x4C\x77\x7B\x32\x0C\x83\x20\x0E\x95\x7F\x14\x68\x00\x28\x3A\x1E\x2C\x0E\x4B\x05\x0D\x1E\x05\x69\x82\x83\x3D\x87",
				"\x84\x53\x16\x6A\x49\x7A\x7C\x7F\x96\x3E\x7F\x0D\xD0\x4D\x85\xCB\x06\x2B\x89\x13\x94\x0F\x64\xC0\x62\x7A\x62\x14\x85\x61\x0D\x1B\x26\x8A\xB5\x6F\x8A\x18\x51\x83\x79\x16\x95\x03\x23\x5F\x99\x8B\xC9\x44\x7E\x20\xC2\x47\x7D\x6D\xFD\x69\x78\x1D\x05\x65\x5A\x83\x2D\x8E\x89\x6F\x13\x34\x45\x59\x4B\x7C\xAD\x34\x09\x08\x8B\x2F\x0C\x0B\xA1\x7B\x89\x81\x0D\x8D\x7E\x54\x11\x8C\x1B\x73\x89\x0C\xB3\x61\x85\x82\x00\x85\x0D\x0A\x1B\x2B\x91\x2C\x82\x94\x90\x70\x04\x0A\xB8\x70\x04\x0C\x3D\xAE\x0C\x8A\x2D\x9D\x63\x40\x1F\x60\x91\x47\x82\x65\x90\xDE\x75\x0D\xC1\x34\x76\x20\x52\xB0\x8A\x8E\x9F\x90\x0D\x1D\xED\x78\x92\x0B\x98\x86\x78\x14\x61\x90\x2A\xF4\x8C\x7C\xF7\x4B\x75\x85\x58\x86\x21\x2E\xA7\x93\x91\x54\xB6\x68\x6F\xB0\x89\x5A\x2C\x85\x35\x90\x95\x6C\x61\x98\x3E\x61\x92\x2A\x9F\x8D\x95\x44\x82\x71\x20\x66\x91\x96\x7D\x65\x0B\x85\xE6\x4E\x24\x93\xA6\x60\x56\x15\x29\x82\x6E\xBA\x45\x89\x74\x79\x66\x21\x38\xA7\x8B\x9B\x0F\xA4\x8A\x5D\xC8\x8D\x6E\x15\x08\x79\x3B\x35\x2F\x79\x91\xB6\x46\x21\x3C\xA7\x87\x0B\xA7\x15\x93\x8F\x89\x83\x28",
				};

			class DarkSkinResourceLoaderPlugin : public Object, public IGuiPlugin
			{
			public:

				GUI_PLUGIN_NAME(GacGen_DarkSkinResourceLoader)
				{
					GUI_PLUGIN_DEPEND(GacUI_Res_Resource);
					GUI_PLUGIN_DEPEND(GacUI_Res_TypeResolvers);
#ifndef VCZH_DEBUG_NO_REFLECTION
					GUI_PLUGIN_DEPEND(GacUI_Instance_Reflection);
					GUI_PLUGIN_DEPEND(GacUI_Compiler_WorkflowTypeResolvers);
#endif
				}

				void Load()override
				{
					List<GuiResourceError> errors;
					MemoryStream resourceStream;
					DarkSkinResourceReader::ReadToStream(resourceStream);
					resourceStream.SeekFromBegin(0);
					auto resource = GuiResource::LoadPrecompiledBinary(resourceStream, errors);
					GetResourceManager()->SetResource(L"DarkSkin", resource, GuiResourceUsage::InstanceClass);
				}

				void Unload()override
				{
				}
			};
			GUI_REGISTER_PLUGIN(DarkSkinResourceLoaderPlugin)
		}
	}
}
