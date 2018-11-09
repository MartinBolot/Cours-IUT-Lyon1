import React, { Component } from 'react';
import Label from "./container/Label";
import Visual from "./container/Visual";

class Robot extends Component {
  constructor(props) {
    super(props);
  }
  render() {
    return (
      <div className="panel panel-default">
        <div className="panel-heading">
          <h3 className="panel-title">Robot {this.props.robot.id} description</h3>
        </div>
        <div className="panel-body">
          <Label label={this.props.robot.label}/>
          <Visual
            type={this.props.robot.visual_type}
            source={this.props.robot.visual_src}/>
          </div>
      </div>

    );
  }
}

export default Robot;
