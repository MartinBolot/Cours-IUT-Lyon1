import React, { Component } from 'react';
import Visual from "./../../Robot/container/Visual";
import Price from "./../../Part/container/Price";

class Panel extends Component {
  render() {
    return(
      <div className="jumbotron">
        <h1 className="display-3">{this.props.part.id}</h1>
        <p className="lead">
          Detailed information of the part {this.props.part.id}
          called {this.props.part.title}
        </p>
        <hr className="my-4"/>
        <div className="container-fluid">
          <div className="row">
            <div className="col-md-6 col-lg-6" >
              <Visual
                type={this.props.part.visual_type}
                src={this.props.part.visual_src}
              />
              <div className="alert alert-info" role="alert">
                <p>ID: {this.props.part.id}</p>
                <p>NAME: {this.props.part.title}</p>
              </div>
              <Price value={this.props.part.price}/>
            </div>
            <div className="col-md-6 col-lg-6" >
              <p> {this.props.part.description}</p>
            </div>
          </div>
        </div>
      </div>
    );
  }
}

export default Panel;
