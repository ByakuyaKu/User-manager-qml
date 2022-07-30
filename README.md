# User-manager-qml 

<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/ByakuyaKu/User-manager-qml"> <img alt="GitHub activity" src="https://img.shields.io/github/last-commit/ByakuyaKu/User-manager-qml"> 


<img src="https://www.altlinux.org/Images.www.altlinux.org/d/d2/Alt_linux_team.png" alt="Logo" width="180" height="180">

 
  
## О проекте
Модуль для управлениями пользователями и группами.
Ранее разработка велась в старом [репозитории](https://github.com/ByakuyaKu/User-manager).

![image](https://user-images.githubusercontent.com/31956595/181862689-68ed87a2-8755-4b31-83ea-b769c19a5b23.png)

### Что было сделано:
* [Модель](https://github.com/ByakuyaKu/User-manager-qml/tree/main/listModel) для представления ListView
* Частично графический интерфейс
* UI элементы [кнопка](https://github.com/ByakuyaKu/User-manager-qml/blob/main/UIElements/CustomBtn.qml) и [кнопка для TabBar](https://github.com/ByakuyaKu/User-manager-qml/blob/main/UIElements/CustomTabBtn.qml)
* Реализовано отображение пользователей при помощи команды "$less /etc/passwd" в классе [LocalUser](https://github.com/ByakuyaKu/User-manager-qml/blob/main/listModel/localuser.cpp#:~:text=QStringList%20LocalUser%3A%3AgetUnparsedLocalUsers)

