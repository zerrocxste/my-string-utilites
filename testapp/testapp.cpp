#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>

const char* string_string(const char* str1, const char* str2)
{
	for (auto i = 0; i < strlen(str1); i++)
	{
		auto iteration_result = true;
		for (auto j = 0; j < strlen(str2); j++)
		{
			auto ch1 = str1[i + j];
			auto ch2 = str2[j];

			if (ch1 == '\0' || ch2 == '\0')
				return 0;

			if (ch1 != ch2)
				iteration_result = false;
		}
		if (iteration_result)
		{
			return str1 + i;
		}
	}

	return 0;
}

bool string_compare(const char* str1, const char* str2)
{
	int i = 0;
	while (true)
	{
		auto is_first_valid = str1[i] != '\0';
		auto is_second_valid = str2[i] != '\0';

		if (i == 0 && (!is_first_valid || !is_second_valid))
			return false;	
			
		if (!is_first_valid && !is_second_valid)
			break;

		if (str1[i] != str2[i]) 
			return false;

		i++;
	}
	return true;
}

int string_length(const char* str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

void string_replace(const char* str, const char* find, const char* replace)
{
	char* buff = (char*)str;

	auto find_size = strlen(find);
	auto replace_size = strlen(replace);

	while (buff = (char*)strstr(buff, find))
	{
		memmove((void*)(buff + replace_size), (void*)(buff + find_size), (size_t)(strlen(buff) + 1));
		memcpy((void*)buff, (void*)replace, replace_size);
		buff += replace_size;
	}
}

int main()
{
	auto example_str = "kajdiy ohotnik jelaet znat' gde sidit fazan";

	printf("%s\n", example_str);

	auto string_string_result = string_string(example_str, "jelaet");
	printf("string string result: va = %p, string from va = %s\n", string_string_result, string_string_result);

	printf("string compare result: %d\n", string_compare(example_str, "kajdiy ohotnik jelaet znat' gde sidit fazan"));

	printf("string length result: %d\n" , strlen(example_str));

	char* str = new char[strlen(example_str)];
	strcpy(str, example_str);

	string_replace(str, "jelaet", "ne jelaet");

	printf("string replace result: %s\n", str);

	system("pause");

	return 1337;
}
