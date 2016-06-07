#include "ezxml.h"

#define dbgprint(...)\
	do\
	{\
		printf("[%s][%d]", __func__, __LINE__);\
		printf(__VA_ARGS__);\
		printf("\n");\
	}while(0);

int xml_writenumber(char *ppath, char *tag, char *item, int number)
{
	ezxml_t  xmlroot = NULL;
	ezxml_t  root = NULL;
	ezxml_t  node = NULL;
	char     sztext[32] = {0};
	char    *xmlstr = NULL;
	FILE    *fp = NULL;

	xmlroot = ezxml_parse_file(ppath);
	if (NULL == xmlroot)
	{
		xmlroot = ezxml_new("root");
		if (NULL == xmlroot)
		{
			dbgprint("create root tag fail for xml(%s)", ppath);
			return -1;
		}
	}

	root = ezxml_child(xmlroot, tag);
	if (NULL == root)
	{
		root = ezxml_add_child_d(xmlroot, tag, 0);
	}

	node = ezxml_child(root, tag);
	if (NULL == node)
	{
		node = ezxml_add_child_d(root, item, 0);
	}

	xmlstr = ezxml_toxml(xmlroot);
	if (NULL == xmlstr)
	{
		ezxml_free(xmlroot);
		dbgprint("fail to tranform xml to string, ppath(%s)", ppath);
		return -1;
	}

	fp = fopen(ppath, "w+");
	if (NULL == fp)
	{
		dbgprint("open file(%s) fail", ppath);
		ezxml_free(xmlroot);
		free(xmlstr);
		return -1;
	}

	fprintf(fp, "%s\n", xmlstr);
	fclose(fp);
	free(xmlstr);
	ezxml_free(xmlroot);

	return 0;
}

int main(int argc, char *argv[])
{
	printf("this is a test of ezxml lib \n");

	xml_writenumber("test.xml", "tag1", "item0", 1);
	xml_writenumber("test.xml", "tag1", "item1", 1);
	xml_writenumber("test.xml", "tag1", "item2", 1);

	xml_writenumber("test.xml", "tag2", "item0", 1);
	xml_writenumber("test.xml", "tag2", "item1", 1);
	xml_writenumber("test.xml", "tag2", "item2", 1);

	return 0;
}
