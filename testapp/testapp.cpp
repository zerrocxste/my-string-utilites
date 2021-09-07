#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>

const char* string_string(const char* str1, const char* str2)
{
	for (size_t i = 0; str1[i] != '\0'; i++)
	{
		auto iteration_result = true;
		for (size_t j = 0; str2[j] != '\0'; j++)
		{
			auto ch1 = str1[i + j];
			auto ch2 = str2[j];

			if (ch1 == '\0')
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
	size_t i = 0;
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

size_t string_length(const char* str)
{
	size_t i = 0;
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

void string_copy(const char* str1, const char* str2, size_t length = 0)
{
	auto need_watch_length = length > 0;
	for (size_t i = 0; i < str2[i] != '\0'; i++)
	{
		*(char*)(str1 + i) = str2[i];
		if (str2[i + 1] == '\0')
			*(char*)(str1 + i + 1) = '\0';
		if (need_watch_length && i > (length - 1))
		{
			*(char*)(str1 + i + 1) = '\0';
			break;
		}
	}
}

const char* boolalpha(bool result)
{
	return result ? "true" : "false";
}

int main()
{
	auto example_str = "kajdiy ohotnik jelaet znat' gde sidit fazan";

	printf("%s\n\n", example_str);

	auto string_string_result = string_string(example_str, "jelaet");
	printf("string string result:\t\t\t\t va = 0x%p, string from va = %s\n", string_string_result, string_string_result);

	printf("string compare result:\t\t\t\t %s\n", boolalpha(string_compare(example_str, "kajdiy ohotnik jelaet znat' gde sidit fazan")));

	printf("string length result:\t\t\t\t %d\n" , strlen(example_str));

	char* str = new char[strlen(example_str)];
	strcpy(str, example_str);

	string_replace(str, "jelaet", "ne jelaet");

	printf("string replace result:\t\t\t\t %s\n", str);

	string_copy(str, "ohotnik idet domoy ibo ystal");

	printf("string copy result:\t\t\t\t %s\n", str);

	string_copy(str, "ohotnik idet !!! no ne hochet kopirovat' bolee 12 simvolov", 12);

	printf("string copy from first 12 symbols result:\t %s\n", str);

	printf("\n");

	system("pause");

	return 1337;
}
