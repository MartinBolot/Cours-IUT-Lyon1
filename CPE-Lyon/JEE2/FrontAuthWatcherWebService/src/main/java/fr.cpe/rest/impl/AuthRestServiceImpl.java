package fr.cpe.rest.impl;

import fr.cpe.model.User;
import fr.cpe.model.UserTransport;
import fr.cpe.rest.AuthRestService;

public class AuthRestServiceImpl implements AuthRestService {
    @Override
    public UserTransport authenticate(User user) {
        System.out.println(user);
        return new UserTransport(user);
    }

    @Override
    public String displayMessage(String message) {
        return "test message";
    }
}
