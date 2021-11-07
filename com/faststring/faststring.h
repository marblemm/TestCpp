class FastString
{
public:
	FastString(const char* psz);
	~FastString();
	int Length(void) const;				//返回字符数目
	int Find(const char* psz) const;	//返回偏移量
private:
	char* m_psz;
};
