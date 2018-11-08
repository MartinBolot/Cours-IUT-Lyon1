package fr.cpe.rest.impl;

import fr.cpe.rest.AuthRestService;

public class AuthRestServiceImpl implements AuthRestService {
    @Override
    public void authenticate(String json) {
        System.out.println(json);
    }

    @Override
    public String displayMessage(String message) {
        return "test message";
    }
}
