#include <iostream>
#include <fstream>
#include <string>
#include <sqlite3.h>

int main()
{
	sqlite3* first_names_DB;

	int db_ret = sqlite3_open("../../../../DB_Builder/db/profile.db", &first_names_DB);
	if (db_ret)
	{
		std::cerr << "Could not open database" << std::endl;
		return -1;
	}
	else
		std::cout << "Database is open" << std::endl;
		
	char* msgErr;

	std::ifstream first_name_file;
	first_name_file.open("../../../../DB_Builder/resrc/names.txt");
	std::string name;
	if (first_name_file.is_open())
	{
		while (getline(first_name_file, name))
		{
			std::cout << "Inserting " + name + " into table" <<std::endl;
			std::string sql = "INSERT INTO Australian_Last (Name) VALUES ('" + name + "')";

			db_ret = sqlite3_exec(first_names_DB, sql.c_str(), NULL, 0, &msgErr);

			if (db_ret != SQLITE_OK)
			{
				if (db_ret == SQLITE_CONSTRAINT_UNIQUE)
					std::cout << "Could not insert " + name + " into table because it's already there." << std::endl;
				else
					std::cout << "Could not insert " + name + " into table. Error " << db_ret << std::endl;

			}
			else
				std::cout << "Inserted " + name + " into table" << std::endl;
		}
	}

	sqlite3_close(first_names_DB);
	
	return 0;
}