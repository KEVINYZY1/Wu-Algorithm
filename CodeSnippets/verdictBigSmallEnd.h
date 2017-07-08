//大端true，小端false
bool verdictBigSmallEnd() {
    int num = 0x12345678;
    char temp = *((char*)&num);
    if (temp == 0x12)
        return true;
    else return false;
}