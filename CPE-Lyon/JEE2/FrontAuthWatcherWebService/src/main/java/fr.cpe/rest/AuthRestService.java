package fr.cpe.rest;

import javax.ws.rs.*;
import javax.ws.rs.core.MediaType;

@Path("watcherauth")
public interface AuthRestService {
    @POST
    @Consumes(MediaType.APPLICATION_JSON)
    void authenticate(String json);

    @GET
    @Produces(MediaType.APPLICATION_JSON)
    String displayMessage(String message);
}