package fr.cpe.model;

import java.io.Serializable;

//@Entity
public class User implements Serializable {

    public User() {
        this.login = "";
        this.pwd = "";
        this.role = "";
    }

    public User(String login, String pwd, String role) {
        this.login = login;
        this.pwd = pwd;
        this.role = role;
    }

    public void setLogin(String login) {
        this.login = login;
    }

    public void setPwd(String pwd) {
        this.pwd = pwd;
    }

    public void setRole(String role) {
        this.role = role;
    }

    public String getLogin() { return this.login; }
    public String getRole() { return this.role; }

    @Override
    public String toString() {
        return "User : " + login;
    }


    private String login;
    private String pwd;
    private String role;
}
