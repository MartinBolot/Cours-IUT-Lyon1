package fr.cpe.rest;

import fr.cpe.model.User;
import fr.cpe.model.UserTransport;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;

@Path("watcherauth")
public interface AuthRestService {
    @POST
    @Consumes(MediaType.APPLICATION_JSON)
    @Produces(MediaType.APPLICATION_JSON)
    UserTransport authenticate(User json);

    @GET
    @Produces(MediaType.APPLICATION_JSON)
    String displayMessage(String message);
}