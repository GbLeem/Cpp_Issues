# Cpp_Issues

### Memory Leak
* TEXT_RPG 폴더의 코드 참고
  * 메모리 누수를 방지하기 위해 raw pointer에서 smart pointer로 교체한 버전
  * 추가) interface 클래스의 소멸자를 virtual로 꼭 만들어주자! (이것이 아래 사진에서 보이는 메모리 누수를 막아준다) <div/>
  
  ![image](https://github.com/user-attachments/assets/1fe2970a-0165-4533-8b70-1214cb5e176e)
