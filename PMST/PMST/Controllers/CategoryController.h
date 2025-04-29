#pragma once

#include "../Models/CategoryModel.h"

using namespace System;
using namespace System::Collections::Generic;

namespace PMST {
	public ref class CategoryController {
	public:
		CategoryController() {}

		
		bool CreateCategory(CategoryModel^ category);
		// Corrected declaration
		static List<CategoryModel^>^ GetAllCategories();
		static void UpdateCategory(CategoryModel^ category);
		static void DeleteCategory(int id);
	};
};
