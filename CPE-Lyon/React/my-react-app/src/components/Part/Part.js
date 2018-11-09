import React, { Component } from 'react';
import Description from "./container/Description";

class Part extends Component {
  render(){
    return(
      <div className="panel panel-default">
        <div className="panel-heading">
          <h3 className="panel-title">Part {this.props.part.id} description</h3>
        </div>
        <div className="panel-body">
          <Description part={this.props.part} />
        </div>
      </div>
    );
  }
}

export default Part;
