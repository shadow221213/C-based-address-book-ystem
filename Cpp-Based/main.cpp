#include <bits/stdc++.h>
using namespace std;
// ��򵥵��Ŀ��
template < typename T > inline T read( ) {
    int f = 1;
    T sum = 0;
    char ch = getchar( );
    while (!isdigit(ch)) {
        if (ch == '-') f = -1;
        ch = getchar( );
    }
    while (isdigit(ch)) {
        sum = (sum << 1) + (sum << 3) + (ch ^ 48);
        ch = getchar( );
    }
    return f * sum;
}
// ͨѶ¼����
const int N = 1e5 + 5;
// �ַ�������
const int M = 1e2 + 2;
// ��������
char weekDay[10][7] = { "������", "����һ", "���ڶ�", "������", "������", "������", "������" };
// ÿ������
int Day[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
// ��ʱ�ı��ַ���
char name[M], phone[M], address[M], workPhone[M];
// ������Ϣ
struct Birthday {
    int year;	// ��
    int month;	// ��
    int day;	// ��
};
// ������Ϣ
struct Person {
    int Sex;	                            // �Ա�
    int Age;	                            // ����
    int Number;	                            // ���
    struct Birthday Birth;	                // ��������
    int Type;	                            // ����
    char Name[M];	                        // ����
    char Phone[M];	                        // �ֻ�����
    char Address[M];	                    // ��λ����
    char WorkPhone[M];	                    // �칫�绰
    bool operator < (const Person a)const {	// �ض���Ƚ������
        return Number < a.Number;
    }
};
// ͨѶ¼
struct Book {
    struct Person Array[N]; // ����ͨѶ¼
    int Size;	            // ͨѶ¼�ִ��С
}Abs;
// ���
int NUMBER( ) {
    int number;
    printf("����-1���˳���ѡ��\n");
    printf("�������ţ�");
    number = read<int>( );
    return number;
}
// ����
inline void NAME( ) {
    printf("������������");
    scanf("%s", name);
}
// �Ա�
inline int SEX( ) {
    int sex;
    printf("1.�� 2.Ů\n");
    printf("�������Ա�");
    while (1) {
        sex = read<int>( );
        if (sex == 1 || sex == 2) break;
        printf("������������������\n");
    }
    return sex;
}
// ����
inline int AGE( ) {
    printf("���������䣺");
    int age;
    while (1) {
        age = read<int>( );
        if (age >= 0) break;
        printf("������������������\n");
    }
    return age;
}
// ��������
inline struct Birthday BIRTH( ) {
    printf("����xxxx xx xx\n");
    printf("���������գ�");
    struct Birthday birth;

    while (1) {
        birth.year = read<int>( );
        if (birth.year >= 0) break;
        printf("������������������\n");
    }

    while (1) {
        birth.month = read<int>( );
        if (birth.month > 0 && birth.month <= 12) break;
        printf("������������������\n");
    }

    while (1) {
        birth.day = read<int>( );
        if (birth.day > 0 && birth.day <= Day[(birth.year % 4 == 0 && birth.year % 100 != 0) ||
            birth.year % 400 == 0][birth.month]) break;
        printf("������������������\n");
    }

    return birth;
}
// ����
inline struct Birthday BIRTHDAY( ) {
    printf("����xx xx\n");
    printf("���������գ�");
    struct Birthday birth = { 0 };

    while (1) {
        birth.month = read<int>( );
        if (birth.month > 0 && birth.month <= 12) break;
        printf("������������������\n");
    }

    while (1) {
        birth.day = read<int>( );
        if (birth.day > 0 && birth.day <= Day[(birth.year % 4 == 0 && birth.year % 100 != 0) ||
            birth.year % 400 == 0][birth.month]) break;
        printf("������������������\n");
    }

    return birth;
}
// ����
inline int TYPE( ) {
    printf("0.�Լ� 1.���� 2.���� 3.ͬѧ 4.ͬ��\n");
    printf("���������ͣ�");
    int type;
    while (1) {
        type = read<int>( );
        if (type >= 0 && type <= 4) break;
        printf("������������������\n");
    }
    return type;
}
// �칫�绰
inline void WORKPHONE( ) {
    printf("������칫�绰��");
    scanf("%s", workPhone);
}
// �ֻ�����
inline void PHONE( ) {
    printf("�������ֻ����룺");
    scanf("%s", phone);
}
// ��λ����
inline void ADDRESS( ) {
    printf("�����뵥λ���ƣ�");
    scanf("%s", address);
}
// kmp�㷨
inline void getNext(int next[], char t[]) {
    int j = 0, k = -1;
    int n = strlen(t);
    next[0] = -1;

    while (j < n - 1)
        if (k == -1 || t[j] == t[k]) {
            j++; k++;
            if (t[j] == t[k]) next[j] = next[k];
            else next[j] = k;
        }
        else k = next[k];
}

inline int kmp(char s[], char t[]) {
    int next[N], i = 0, j = 0;
    int n = strlen(s);
    int m = strlen(t);
    getNext(next, t);

    while (i < n && j < m)
        if (j == -1 || s[i] == t[j]) {
            i++;
            j++;
        }
        else j = next[j];

    if (j >= m) return (i - m);
    else return (-1);
}
// ������ϵ��
inline int findNumber(int x) {
    int l = 0;
    int r = Abs.Size;
    while (l < r) {
        int mid = l + r >> 1;
        if (Abs.Array[mid].Number == x) return mid;
        else if (Abs.Array[mid].Number < x) l = mid + 1;
        else r = mid;
    }
    return -1;
}
// �жϽ����Ƿ����˹�����
inline bool FindBirthDay( ) {
    time_t now = time(NULL);
    tm * time = localtime(&now);

    struct Birthday birth = { time->tm_year + 1900, time->tm_mon + 1, time->tm_mday };

    bool cnt = false;
    for (int i = 0; i < Abs.Size; i++)
        if (Abs.Array[i].Birth.month == birth.month &&
            Abs.Array[i].Birth.day == birth.day)
            cnt = true;

    return cnt;
}
// ����
inline void sys( ) {
    system("pause");
    system("cls");
}
// ������ϵ��
inline bool ALL(int x) {
    int number = NUMBER( );
    if (number < 0) {
        sys( );
        return false;
    }

    if (x == Abs.Size && findNumber(number) != -1) {
        printf("����ϵ���Ѵ���\n");

        sys( );
        return false;
    }
    Abs.Array[x].Number = number;

    NAME( );
    strcpy(Abs.Array[x].Name, name);

    Abs.Array[x].Sex = SEX( );

    Abs.Array[x].Age = AGE( );

    Abs.Array[x].Birth = BIRTH( );

    Abs.Array[x].Type = TYPE( );

    PHONE( );
    strcpy(Abs.Array[x].Phone, phone);

    ADDRESS( );
    strcpy(Abs.Array[x].Address, address);

    WORKPHONE( );
    strcpy(Abs.Array[x].WorkPhone, workPhone);

    return true;
}
// ���޴���
inline void notFound( ) {
    printf("���޴���\n");
    sys( );
}
// ������ʷ����
inline void start( ) {
    FILE * fp = fopen("in.txt", "r");

    if (fp == NULL) return;
    // �ļ�����
    int number;
    while (fscanf(fp, "%d", &number) != EOF) {
        int x = Abs.Size;
        if (findNumber(number) != -1) x = findNumber(number);
        Abs.Array[x].Number = number;

        fscanf(fp, "%s", name);
        strcpy(Abs.Array[x].Name, name);

        int sex;
        fscanf(fp, "%d", &sex);
        Abs.Array[x].Sex = sex;

        int age;
        fscanf(fp, "%d", &age);
        Abs.Array[x].Age = age;

        struct Birthday birth;
        fscanf(fp, "%d %d %d", &birth.year, &birth.month, &birth.day);
        Abs.Array[x].Birth = birth;

        int type;
        fscanf(fp, "%d", &type);
        Abs.Array[x].Type = type;

        fscanf(fp, "%s", phone);
        strcpy(Abs.Array[x].Phone, phone);

        fscanf(fp, "%s", address);
        strcpy(Abs.Array[x].Address, address);

        fscanf(fp, "%s", workPhone);
        strcpy(Abs.Array[x].WorkPhone, workPhone);

        if (x == Abs.Size) Abs.Size++;
    }

    fclose(fp);
}
// ������ʷ����
inline void end( ) {
    FILE * fp = fopen("in.txt", "w");
    // �ļ����
    for (int i = 0; i < Abs.Size; i++) {
        fprintf(fp, "%d ", Abs.Array[i].Number);
        fprintf(fp, "%s ", Abs.Array[i].Name);
        fprintf(fp, "%d %d ", Abs.Array[i].Sex, Abs.Array[i].Age);
        fprintf(fp, "%d %d %d ",
            Abs.Array[i].Birth.year, Abs.Array[i].Birth.month, Abs.Array[i].Birth.day);
        fprintf(fp, "%d ", Abs.Array[i].Type);
        fprintf(fp, "%s %s %s\n",
            Abs.Array[i].Phone, Abs.Array[i].Address, Abs.Array[i].WorkPhone);
    }

    fclose(fp);
}
// ��ʾ���ҽ��
inline void showResult(int i) {
    printf("#################################################\n");
    printf("��ţ�%d\n", Abs.Array[i].Number);
    printf("������%s\n", Abs.Array[i].Name);
    printf("�Ա�");
    if (Abs.Array[i].Sex == 1) printf("��\n");
    else printf("Ů\n");
    printf("���䣺%d\n", Abs.Array[i].Age);
    printf("��λ��%s\n", Abs.Array[i].Address);
    printf("���ͣ�");
    switch (Abs.Array[i].Type) {
    case 0:
        printf("�Լ�\n");
        break;
    case 1:
        printf("����\n");
        break;
    case 2:
        printf("����\n");
        break;
    case 3:
        printf("ͬѧ\n");
        break;
    case 4:
        printf("ͬ��\n");
        break;
    }
    printf("�������ڣ�%04d-%02d-%02d\n",
        Abs.Array[i].Birth.year, Abs.Array[i].Birth.month, Abs.Array[i].Birth.day);
    printf("�칫�绰��%s\n", Abs.Array[i].WorkPhone);
    printf("�ֻ����룺%s\n", Abs.Array[i].Phone);
    printf("#################################################\n");
}
// ��ʾ���ӷ�
inline void showBuddha( );
// �˳�ͨѶ¼
inline void exitBook( ) {
    end( );
    sys( );
    showBuddha( );
    sys( );
    exit(0);
}
// �����ϵ��
inline void addPerson( ) {
    if (Abs.Size == N) {
        printf("ͨѶ¼���������޷��������ϵ��\n");

        sys( );
        return;
    }

    if (!ALL(Abs.Size)) return;
    Abs.Size++;
    sort(Abs.Array, Abs.Array + Abs.Size);

    printf("��ӳɹ�\n");
    sys( );
}
// ��ʾ��ϵ��
inline void showPerson( ) {
    if (!Abs.Size) {
        printf("��ʱ��û����ϵ��\n");

        sys( );
        return;
    }

    for (int i = 0; i < Abs.Size; i++)
        showResult(i);
    sys( );
}
// ɾ����ϵ��
inline void deletePerson( ) {
    int number = NUMBER( );
    if (number < 0) {
        sys( );
        return;
    }

    int cnt = findNumber(number);
    if (cnt == -1) {
        notFound( );
        return;
    }

    for (int i = cnt; i < Abs.Size; i++)
        Abs.Array[i] = Abs.Array[i + 1];
    Abs.Size--;
    printf("ɾ���ɹ�\n");
    sys( );
}
// ���Ҳ˵�
inline void showFind( ) {
    printf("#################################################\n");
    printf("##################### 1.��� ####################\n");
    printf("##################### 2.���� ####################\n");
    printf("##################### 3.���� ####################\n");
    printf("##################### 4.���� ####################\n");
    printf("#################################################\n");
    printf("��ѡ��Ҫ��ѯ�����ݣ�");
}
// ���ұ��
inline void FindNumber( ) {
    int number = NUMBER( );
    if (number < 0) {
        sys( );
        return;
    }

    int cnt = findNumber(number);
    if (cnt == -1) {
        notFound( );
        return;
    }

    showResult(cnt);
    sys( );
}
// ��������
inline void FindBirth(struct Birthday birth) {
    bool cnt = false;
    for (int i = 0; i < Abs.Size; i++)
        if (Abs.Array[i].Birth.month == birth.month &&
            Abs.Array[i].Birth.day == birth.day) {
            showResult(i);
            cnt = true;
        }

    if (!cnt) {
        notFound( );
        return;
    }
    sys( );
}
// ��������
inline void FindName( ) {
    NAME( );

    bool cnt = false;
    for (int i = 0; i < Abs.Size; i++)
        if (kmp(Abs.Array[i].Name, name) != -1) {
            showResult(i);
            cnt = true;
        }

    if (!cnt) {
        notFound( );
        return;
    }
    sys( );
}
// ��������
inline void FindType( ) {
    int type = TYPE( );

    bool cnt = false;
    for (int i = 0; i < Abs.Size; i++)
        if (Abs.Array[i].Type == type) {
            showResult(i);
            cnt = true;
        }

    if (!cnt) {
        notFound( );
        return;
    }
    sys( );
}
// ��ѯ��ϵ��
inline void findPerson( ) {
    showFind( );

    int Select = read<int>( );
    struct Birthday birth;
    switch (Select) {
    case 1:
        FindNumber( );
        break;
    case 2:
        FindName( );
        break;
    case 3:
        birth = BIRTHDAY( );
        FindBirth(birth);
        break;
    case 4:
        FindType( );
        break;
    default:
        printf("������������������\n");
        sys( );
        break;
    }
}
// �޸���ϵ��
inline void modifyPerson( ) {
    int number = NUMBER( );
    if (number < 0) {
        sys( );
        return;
    }

    int cnt = findNumber(number);
    if (cnt == -1) {
        notFound( );
        return;
    }
    if (!ALL(cnt)) return;

    sort(Abs.Array, Abs.Array + Abs.Size);
    sys( );
}
// �����ϵ��
inline void clearPerson( ) {
    Abs.Size = 0;
    printf("��ͨѶ¼�����\n");
    sys( );
}
// ���������ϵ��
inline void batchAddPerson( ) {
    FILE * fp = fopen("add.txt", "r");

    if (fp == NULL) return;
    // �ļ�����
    int number;
    while (fscanf(fp, "%d", &number) != EOF) {
        int x = Abs.Size;
        int cnt = findNumber(number);
        if (cnt != -1) x = cnt;
        Abs.Array[x].Number = number;

        fscanf(fp, "%s", name);
        strcpy(Abs.Array[x].Name, name);

        int sex;
        fscanf(fp, "%d", &sex);
        Abs.Array[x].Sex = sex;

        int age;
        fscanf(fp, "%d", &age);
        Abs.Array[x].Age = age;

        struct Birthday birth;
        fscanf(fp, "%d %d %d", &birth.year, &birth.month, &birth.day);
        Abs.Array[x].Birth = birth;

        int type;
        fscanf(fp, "%d", &type);
        Abs.Array[x].Type = type;

        fscanf(fp, "%s", phone);
        strcpy(Abs.Array[x].Phone, phone);

        fscanf(fp, "%s", address);
        strcpy(Abs.Array[x].Address, address);

        fscanf(fp, "%s", workPhone);
        strcpy(Abs.Array[x].WorkPhone, workPhone);

        if (x == Abs.Size) Abs.Size++;
    }

    fclose(fp);

    sort(Abs.Array, Abs.Array + Abs.Size);
    printf("�������\n");
    sys( );
}
// ��ȡ���չ����յ���
inline void getBirthday( ) {
    printf("��������յ��У�\n");

    time_t now = time(NULL);
    tm * time = localtime(&now);

    struct Birthday birth = { time->tm_year + 1900, time->tm_mon + 1, time->tm_mday };
    FindBirth(birth);
}
// ��ȡ��ǰʱ��
inline void getTime( ) {
    time_t now = time(NULL);
    tm * time = localtime(&now);

    printf("#################################################\n");
    printf("����ʱ�䣺%04d��%02d��%02d�� %s ",
        time->tm_year + 1900, time->tm_mon + 1, time->tm_mday, weekDay[time->tm_wday]);
    printf("%02d:%02d:%02d\n", time->tm_hour, time->tm_min, time->tm_sec);
    printf("#################################################\n");

    sys( );
}
// ������
inline void showMenu( ) {
    printf("#################################################\n");
    printf("################# ͨѶ¼����ϵͳ ################\n");
    printf("#################################################\n");
    printf("################## 1.�����ϵ�� #################\n");
    printf("################## 2.��ʾ��ϵ�� #################\n");
    printf("################## 3.ɾ����ϵ�� #################\n");
    printf("################## 4.������ϵ�� #################\n");
    printf("################## 5.�޸���ϵ�� #################\n");
    printf("################## 6.�����ϵ�� #################\n");
    printf("################## 0.�˳�ͨѶ¼ #################\n");
    printf("#################################################\n");
    printf("################ 7.�鿴��ǰʱ��� ###############\n");
    printf("################ 8.���������ϵ�� ###############\n");
    printf("# �뽫���������Ϣ�ļ�����Ϊ\"add.txt\", ANSI���� #\n");
    printf("# ˳��:���,����,�Ա�,����,��������,����,�绰�� #\n");
    printf("########## ����˳��: ��λ����,�칫�绰 ##########\n");
    printf("# �����Ա�֤������Ϣ����ȷ��,�����򲻶��俱�� #\n");
    if (FindBirthDay( )) {
        printf("#################################################\n");
        printf("###### ������ĳ�˵����գ�����9ף�����տ��� ######\n");
    }
    printf("#################################################\n");
    printf("������ѡ�");
}
// ѡ�����
inline void showSelect( ) {
    showMenu( );

    int Select = read<int>( );
    switch (Select) {
    case 0:
        exitBook( );
        break;
    case 1:
        addPerson( );
        break;
    case 2:
        showPerson( );
        break;
    case 3:
        deletePerson( );
        break;
    case 4:
        findPerson( );
        break;
    case 5:
        modifyPerson( );
        break;
    case 6:
        clearPerson( );
        break;
    case 7:
        getTime( );
        break;
    case 8:
        batchAddPerson( );
        break;
    case 9:
        getBirthday( );
        break;
    default:
        printf("������������������\n");
        sys( );
        break;
    }
}

signed main( ) {
    Abs.Size = 0;
    start( );
    while (1)
        showSelect( );

    return 0;
}
// ��ʾ���ӷ�
inline void showBuddha( ) {
    printf("#################################################\n");
    printf("############### �ڴ������´�ʹ��! ###############\n");
    printf("#################################################\n");
    printf("                    _oo0oo_ \n");
    printf("                   o8888888o \n");
    printf("                  888\" . \"888 \n");
    printf("                 (|  - _ -  |) \n");
    printf("                 0\\    =    /0 \n");
    printf("           ______ /\\_______/\\ ______ \n");
    printf("          /  |||          | //   \". \\ \n");
    printf("         /  \\\\/|      '   / ||    \"| \\ \n");
    printf("        /  __/||       -:-|||| / \\--- \\ \n");
    printf("        |     | \\ ||   - ///  |    |  | \n");
    printf("        \\  |__|  ''\\|__'_'  __/-.  /  / \n");
    printf("        / | .-\\_____        ______/-./ \n");
    printf("       _____\"'.\"    / --.--|   '.  .  ___ \n");
    printf("      /  '<   .___\\_<|>_/ ___.'  > ' = = \\ \n");
    printf("      |  | : - / ' ./' \ _ / ';. / - ' :| | \n");
    printf("      \\  \\ | '_-. ' /_ __ / '_. . /   _ ./ \n");
    printf("======= -.______ =.______/ ______/____.- ======== \n");
    printf("#################################################\n");
    printf("############### ���ӷ���ɢ����bug ###############\n");
    printf("############### ������ʦ,�����߷� ###############\n");
    printf("#################################################\n");
}