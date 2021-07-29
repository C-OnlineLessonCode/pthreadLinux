void* tfunc(void* param) {

std::cout << param << std::endl;
return nullptr;
}

int main()
{
pthread_t tid = 0;
pthread_attr_t attr = {};
pthread_attr_init(&attr);

pthread_create(&tid, &attr, tfunc, 0);
sleep(1);

void* data;
pthread_join(tid, &data);
cout << "Hello World!" << endl;
return 0;
} 
