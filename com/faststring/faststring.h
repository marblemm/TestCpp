class FastString
{
public:
	FastString(const char* psz);
	~FastString();
	int Length(void) const;				//�����ַ���Ŀ
	int Find(const char* psz) const;	//����ƫ����
private:
	char* m_psz;
};
