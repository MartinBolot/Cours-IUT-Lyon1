package fr.cpe.model;

import java.io.Serializable;

public class UserTransport implements Serializable {

    public UserTransport(User user) {
        this.login = user.getLogin();
        this.role = user.getRole();
        this.validAuth = false;
    }

    public String getLogin() {
        return this.login;
    }

    public String getRole() {
        return this.role;
    }

    public boolean getValidAuth() {
        return this.validAuth;
    }

    private String login;
    private String role;
    private boolean validAuth = false;
}
