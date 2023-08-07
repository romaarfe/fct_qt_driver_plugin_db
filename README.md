<h3 align="center"> 
  🚧 PROJETO DRIVER DATABASE 🚧
</h3>

---
#### ⚙️ ETAPAS / FUNCIONALIDADES:

- [x] Criação de plugin para uso de nova base de dados no QT
- [x] Promover encriptação através do SQLCipher
- [x] Permitir que este driver, QSQLCipher, trabalhe tanto com SQLite quanto com SQLCipher
- [x] Fazer load do driver/plugin com todas suas funções associadas
- [x] Implementação do código associado
- [x] Testes da funcionalidades, seja através da criação de base de dados encriptada quanto apresentação de seu conteúdo

---
#### ⚠️ NOTAS IMPORTANTES:

- O **.setPasword()** do próprio QT (QSqlDatabase) ainda trabalha com SQLite, que por sua vez não concebe uso de senhas
- Para encriptação utilizar um **.exec()** e **"PRAGMA key = 'sua_senha_aqui';"**

---
#### 🔧 FERRAMENTAS / TECNOLOGIAS:

- C
- C++
- CMake
- QT Framework
- SQLite (QSQLite)
- SQLCipher

---
##### 👨‍💻 Desenvolvido na SDILAB - Research & Software Development 
##### ⚖️ Balanças Marques - Grupo José Pimenta Marques
##### 📖 Projeto para Formação em Contexto de Trabalho - IEFP
